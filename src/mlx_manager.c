/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:09:16 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/15 20:19:54 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "test");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	if (!ft_create_images(data))
		return (1);
	ft_put_map(data);
	return (0);
}

int	ft_create_images(t_data *data)
{
	t_assets	assets;

	assets.character.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, 
		CHARAC, &assets.character.w, &assets.character.h);
	if (!assets.character.img_ptr)
		return (0);
	assets.wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, WALL, 
		&assets.wall.w, &assets.wall.h);
	if (!assets.wall.img_ptr)
		return (0);
	assets.ground.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, GROUND, 
		&assets.ground.w, &assets.ground.h);
	if (!assets.ground.img_ptr)
		return (0);
	assets.end.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, END, 
		&assets.end.w, &assets.end.h);
	if (!assets.end.img_ptr)
		return (0);
	assets.poke.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, COLLEC, 
		&assets.poke.w, &assets.poke.h);
	if (!assets.poke.img_ptr)
		return (0);
	data->assets = assets;
	return (1);
}

void	ft_put_image(t_data *data, t_img img, t_coord i)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
 		img.img_ptr, i.y * 64, i.x * 64);
}

void draw_transparency(t_data *data, t_img img, t_coord c)
{
	t_coord i;
	t_img 	cpy;

    cpy.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, 
		GROUND, &cpy.w, &cpy.h);
    cpy.data = mlx_get_data_addr(cpy.img_ptr, 
		&cpy.bpp, &cpy.size_line, &cpy.endian);
	img.data = mlx_get_data_addr(img.img_ptr, 
		&img.bpp, &img.size_line, &img.endian);
	i.x = 0;
	while (i.x < img.h)
	{
		i.y = 0;
		while (i.y < img.w)
		{
			if (img.data[(i.x * img.size_line) + (i.y * (img.bpp / 8))] != 0)
			{
				cpy.data[(i.x * cpy.size_line) + (i.y * (cpy.bpp / 8))]
				= img.data[(i.x * img.size_line) + (i.y * (img.bpp / 8))];
				cpy.data[(i.x * cpy.size_line) + (i.y * (cpy.bpp / 8) + 1)]
				= img.data[(i.x * img.size_line) + (i.y * (img.bpp / 8) + 1)];
				cpy.data[(i.x * cpy.size_line) + (i.y * (cpy.bpp / 8) + 2)]
				= img.data[(i.x * img.size_line) + (i.y * (img.bpp / 8) + 2)];
			}
			i.y++;
		}
		i.x++;
	}
	ft_put_image(data, cpy, c);
	free(cpy.img_ptr);
}

void ft_refresh(t_data *data, t_coord i)
{
	if (data->map[i.x][i.y] == '0')
		ft_put_image(data, data->assets.ground, i);
	else if (data->map[i.x][i.y] == '1')
		draw_transparency(data, data->assets.wall, i);
	else if (data->map[i.x][i.y] == 'P')
		draw_transparency(data, data->assets.character, i);
	else if (data->map[i.x][i.y] == 'E')
		draw_transparency(data, data->assets.end, i);
	else if (data->map[i.x][i.y] == 'C')
		draw_transparency(data, data->assets.poke, i);
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
