/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:53 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/22 19:10:51 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_charac(t_data *data, t_coord p)
{
	if (data->is_attacking == 1)
	{
		if (data->att_i == 0)
			draw_transparency(data, data->assets.att1, p);
		else if (data->att_i == 1)
			draw_transparency(data, data->assets.att2, p);
	}
	else if (data->charac_ori == 'u')
		draw_transparency(data, data->assets.charac_up, p);
	else if (data->charac_ori == 'd')
		draw_transparency(data, data->assets.charac_down, p);
	else if (data->charac_ori == 'l')
		draw_transparency(data, data->assets.charac_left, p);
	else if (data->charac_ori == 'r')
		draw_transparency(data, data->assets.charac_right, p);
}

static void	ft_draw_hud(t_data *data)
{
	char	*poke;
	char	*move;

	poke = ft_itoa(data->nb_picked);
	move = ft_itoa(data->nb_move);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->assets.hud.img_ptr, 0, 0);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 132, 16, 0x000000, move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 132, 46, 0x000000, poke);
	free(move);
	free(poke);
}

static void	ft_draw_ennemies(t_data *data, t_coord i)
{
	if (data->map[i.x][i.y] == '2')
	{
		if (data->enn_sprite == 0)
			draw_transparency(data, data->assets.enn1, i);
		else
			draw_transparency(data, data->assets.enn2, i);
	}
	else if (data->map[i.x][i.y] == '3')
	{
		if (data->enn_sprite == 0)
			draw_transparency(data, data->assets.enn2_1, i);
		else
			draw_transparency(data, data->assets.enn2_2, i);
	}
}

void	ft_refresh(t_data *data, t_coord i)
{
	if (data->map[i.x][i.y] == '0')
		ft_put_image(data, data->assets.ground, i);
	else if (data->map[i.x][i.y] == '1')
		draw_transparency(data, data->assets.wall, i);
	else if (data->map[i.x][i.y] == 'P')
	{
		ft_draw_charac(data, *data->game_obj.player);
	}
	else if (data->map[i.x][i.y] == 'E')
	{
		if (data->nb_poke == ft_lstsize(data->game_obj.collecs))
			draw_transparency(data, data->assets.end2, i);
		else
			draw_transparency(data, data->assets.end, i);
	}
	else if (data->map[i.x][i.y] == 'C')
		draw_transparency(data, data->assets.poke, i);
	ft_draw_ennemies(data, i);
	ft_draw_hud(data);
}

void	ft_put_map(t_data *data)
{
	t_coord	i;

	i.x = 0;
	while (data->map[i.x])
	{
		i.y = 0;
		while (data->map[i.x][i.y])
		{
			ft_refresh(data, i);
			i.y++;
		}
		i.x++;
	}
}
