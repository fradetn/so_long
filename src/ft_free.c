/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:49:52 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/10 15:25:39 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tab, t_game_obj *go)
{
	free(go->end);
	free(go->player);
	ft_lstclear(&(go->collecs), &ft_free_coord);
	ft_free_tab(tab);
	free(go);
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
