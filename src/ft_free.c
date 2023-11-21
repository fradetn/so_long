/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:49:52 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/21 14:08:05 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_inv(t_data *data)
{
	ft_free_go(&data->game_obj);
	ft_free_tab(data->map);
	free(data->mlx_ptr);
}

void	ft_free(t_data *data)
{
	ft_free_go(&data->game_obj);
	ft_free_tab(data->map);
	ft_free_asset(data, &data->assets);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	ft_free_asset(t_data *data, t_assets *assets)
{
	mlx_destroy_image(data->mlx_ptr, assets->charac_up.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->charac_down.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->charac_left.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->charac_right.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->ground.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->poke.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->end.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->end2.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->enn1.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->enn2.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->hud.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->att1.img_ptr);
	mlx_destroy_image(data->mlx_ptr, assets->att2.img_ptr);
}

void	ft_free_go(t_game_obj *go)
{
	free(go->end);
	free(go->player);
	ft_lstclear(&(go->collecs), &ft_free_coord);
	ft_lstclear(&(go->enn1), &ft_free_coord);
}

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_free_coord(void *coord)
{
	free(coord);
}
