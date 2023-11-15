/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:07:24 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/15 21:16:08 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char		*file_name;
	t_data		data;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	data.map = file_to_tab(file_name);
	data.game_obj = fill_objs(data.map);
	data.nb_poke = 0;
	data.nb_move = 0;
 	if (check_map(&data) == 1)
	{
		ft_free_inv(&data);
		free(file_name);
		return (1);
	}
	ft_init_mlx(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop(data.mlx_ptr);
	free(file_name);
	ft_free(&data);
	free(data.mlx_ptr);
	free(data.win_ptr);
	return (0);
}
