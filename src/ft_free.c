/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:49:52 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/16 00:12:40 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_inv(t_data *data)
{
	ft_free_go(&data->game_obj);
	ft_free_tab(data->map);
}

void	ft_free(t_data *data)
{
	ft_free_go(&data->game_obj);
	ft_free_tab(data->map);
	ft_free_asset(data->assets);
}

void	ft_free_asset(t_assets assets)
{
	free(assets.charac_up.img_ptr);
	free(assets.charac_down.img_ptr);
	free(assets.charac_left.img_ptr);
	free(assets.charac_right.img_ptr);
	free(assets.wall.img_ptr);
	free(assets.ground.img_ptr);
	free(assets.poke.img_ptr);
	free(assets.end.img_ptr);
}

void	ft_free_go(t_game_obj *go)
{
	free(go->end);
	free(go->player);
	ft_lstclear(&(go->collecs), &ft_free_coord);
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
