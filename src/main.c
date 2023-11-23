/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:07:24 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/23 18:22:20 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_enn_sprite(t_data *data)
{
	t_list	*enn1;
	t_list	*enn2;

	enn1 = data->game_obj.enn1;
	enn2 = data->game_obj.enn2;
	while (enn1)
	{
		ft_refresh(data, *(t_coord *)enn1->content);
		enn1 = enn1->next;
	}
	while (enn2)
	{
		ft_refresh(data, *(t_coord *)enn2->content);
		enn2 = enn2->next;
	}
}

int	update_sprite_phase(t_data *data)
{
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
		data->clock = 0;
		update_enn_sprite(data);
	}
	data->clock++;
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_free(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	char		*file_name;
	t_data		data;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);
	ft_init_data(&data, file_name);
	free(file_name);
	if (check_map(&data) == 1)
	{
		ft_printf("map invalide");
		ft_free_inv(&data);
		return (1);
	}
	ft_init_mlx(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_window, &data);
	mlx_loop_hook(data.mlx_ptr, update_sprite_phase, &data);
	mlx_loop(data.mlx_ptr);
	ft_free(&data);
	return (0);
}
