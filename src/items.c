/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:34:00 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/06 06:07:49 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*create_coord(int x, int y)
{
	t_coord *coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	if (!coord)
		return (NULL);
	coord->x = x;
	coord->y = y;
	return (coord);
}

/* 
* Recupere la position du joueur et la remvoie.
* renvoie NULL si il n'y a pas de joueur
*/
t_coord	*get_char_pos(char **tab, char c)
{
	t_coord	*pos;
	int		x;
	int		y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == c)
			{
				pos = create_coord(x, y);
				return (pos);
			}
			y++;
		}
		x++;
	}
	return (NULL);
}

/*
* Enregistre les coordonees de tous les
* collectibles dans une liste chainee
*/
t_list	*get_all_collec(char **tab)
{
	t_list	*list;
	t_list	*new;
	t_coord	*coord;
	int		x;
	int		y;

	x = 0;
	list = NULL;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == 'C')
			{
				coord = create_coord(x, y);
				new = ft_lstnew(coord);
				ft_lstadd_back(&list, new);
			}
			y++;
		}
		x++;
	}
	return (list);
}
