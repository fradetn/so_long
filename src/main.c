/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:07:24 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/21 14:09:37 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

int update_sprite_phase(t_data *data)
{
	t_list	*lst;

	lst = data->game_obj.enn1;
	if (data->clock == 3000)
	{
		if (data->is_attacking == 1)
		{
			ft_refresh(data, *data->game_obj.player);
			data->att_i++;
			if (data->att_i == 2)
			{
				data->is_attacking = 0;
				data->att_i = 0;
			}
		}
		else
			ft_refresh(data, *data->game_obj.player);
		data->enn_sprite = (data->enn_sprite + 1) % 2;
		while (lst)
		{
			ft_refresh(data, *(t_coord *)lst->content);
			lst = lst->next;
		}
		data->clock = 0;
	}
	data->clock++;
	return (0);
}

int	close_window(t_data *data)
{
	ft_printf("test");
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free(data);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	char		*file_name;
	t_data		data;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	data.map = file_to_tab(file_name);
	data.game_obj = fill_objs(data.map);
	data.nb_poke = 0;
	data.nb_picked = 0;
	data.nb_move = 0;
	data.enn_sprite = 0;
	data.clock = 0;
	data.att_i = 0;
	data.is_attacking = 0;
	data.charac_ori = 'd';
 	if (check_map(&data) == 1) 	{
		ft_free_inv(&data);
		free(file_name);
		return (1);
	}
	ft_init_mlx(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.assets.hud.img_ptr, 0, 0);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop_hook(data.mlx_ptr, update_sprite_phase, &data);
	mlx_loop(data.mlx_ptr);
	free(file_name);
	ft_free(&data);
	free(data.mlx_ptr);
	free(data.win_ptr);
	return (0);
}
