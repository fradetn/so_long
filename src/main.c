/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:07:24 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/10 15:48:58 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int	key_hook(int keycode, t_data *data)
{
	(void) data;
	ft_printf("keycode : %d\n", keycode);
	return (0);
}

int main(int argc, char **argv)
{
	char		**tab;
	char		*file_name;
	t_data		data;
	t_game_obj	*game_obj;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	tab = file_to_tab(file_name);
	// ft_printf("%s", file_name);
	game_obj = fill_objs(tab);
 	if (check_map(tab, game_obj) == 1)
	{
		ft_printf("La map fournie est invalide !");
		ft_free(tab, game_obj);
		free(file_name);
		return (1);
	}

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "./assets/tileset_wall.xpm", &data.w, &data.h);
	if (!data.img_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 300, 300, "test");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_put_image_to_window(data.mlx_ptr,data.win_ptr, data.img_ptr, 0, 0);
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