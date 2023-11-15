/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:07:24 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/15 17:03:37 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




int main(int argc, char **argv)
{
	char		**tab;
	char		*file_name;
	t_data		data;
	t_game_obj	*game_obj;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	tab = file_to_tab(file_name);
	game_obj = fill_objs(tab);
 	if (check_map(tab, game_obj) == 1)
	{
		ft_printf("La map fournie est invalide !");
		ft_free(tab, game_obj);
		free(file_name);
		return (1);
	}
	ft_init_mlx(&data, tab);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop(data.mlx_ptr);
	free(file_name);
	ft_free(tab, game_obj);
	return (0);
}

/* int main(int argc, char **argv)
{
	// void	*mlx_ptr;
	char		**tab;
	char		*file_name;
	// t_game_obj	game_obj;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	tab = file_to_tab(file_name);
	ft_printf("%d",check_objs(tab));
	free(file_name);
	ft_free(tab);
}  */