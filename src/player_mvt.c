/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:23 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/22 19:34:29 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_valid(t_data *data, t_coord move)
{
	if (data->map[move.x][move.y] == '1')
		return (0);
	else if (data->map[move.x][move.y] == 'E')
	{
		if (data->nb_poke != ft_lstsize(data->game_obj.collecs))
			return (0);
	}
	return (1);
}

void	ft_action(t_data *data, t_coord move)
{
	if (data->map[move.x][move.y] == '0')
		ft_swap_val(data->map, move, *(data->game_obj.player));
	else if (data->map[move.x][move.y] == 'C')
	{
		data->map[move.x][move.y] = 'P';
		data->map[data->game_obj.player->x][data->game_obj.player->y] = '0';
		data->nb_poke += 1;
		data->nb_picked += 1;
		if (data->nb_poke == ft_lstsize(data->game_obj.collecs))
			ft_refresh(data, *data->game_obj.end);
	}
	else if (data->map[move.x][move.y] == '2' ||
	data->map[move.x][move.y] == '3')
	{
		ft_printf("VOUS ETES MORT !\n");
		close_window(data);
	}
	else if (data->map[move.x][move.y] == 'E')
	{
		ft_printf("BRAVO, VOUS AVEZ GAGNÉ !\n");
		close_window(data);
	}
}

int	ft_move(t_data *data, int x, int y)
{
	t_coord	move;
	t_coord	prev_player;

	move.x = data->game_obj.player->x + x;
	move.y = data->game_obj.player->y + y;
	if (move_valid(data, move) && data->is_attacking == 0)
	{
		prev_player = *data->game_obj.player;
		ft_action(data, move);
		free(data->game_obj.player);
		data->game_obj.player = get_char_pos(data->map, 'P');
		ft_refresh(data, move);
		ft_refresh(data, prev_player);
		data->nb_move += 1;
		ft_printf("nb_move : %d\n", data->nb_move);
		ft_printf("nb_poke : %d\n\n", data->nb_picked);
		return (1);
	}
	return (0);
}

void	ft_attack(t_data *data)
{
	t_coord	p;

	p = *data->game_obj.player;
	if (data->nb_picked > 0 && data->is_attacking == 0)
	{
		ft_attack_h(data, p);
		if (data->map[p.x - 1][p.y] == '2' || data->map[p.x - 1][p.y] == '3')
		{
			data->nb_picked--;
			data->is_attacking = 1;
			data->map[p.x - 1][p.y] = '0';
			p.x -= 1;
		}
		else if (data->map[p.x + 1][p.y] == '2' ||
		data->map[p.x + 1][p.y] == '3')
		{
			data->nb_picked--;
			data->is_attacking = 1;
			data->map[p.x + 1][p.y] = '0';
			p.x += 1;
		}
	}
	else
		ft_printf("Pokeballs insuffisantes\n");
	ft_refresh(data, p);
}

int	key_hook(int keycode, t_data *data)
{
	key_move(keycode, data);
	if (keycode == 32)
		ft_attack(data);
	else if (keycode == 65307)
		close_window(data);
	return (0);
}
