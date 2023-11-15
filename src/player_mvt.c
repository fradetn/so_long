/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mvt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:56:23 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/15 17:34:11 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_valid(char **tab, t_coord move)
{
	if (tab[move.x][move.y] = '1')
		return (0);
}


int	ft_move(t_data *data, int x, int y)
{
	t_coord	move;

	move.x = data->game_obj.player->x + x;
	move.y = data->game_obj.player->y + y;
	if (move_valid(data->tab, move))
	{

	}
}


int	key_hook(int keycode, t_data *data)
{
	(void) data;
	if (keycode == 119)
		ft_move(data, -1, 0);
	else if (keycode == 115)
		ft_move(data, -1, 0);
	else if (keycode == 97)
		ft_printf("left\n");
	else if (keycode == 100)
		ft_printf("right\n");
	return (0);
}
