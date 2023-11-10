/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:07:20 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/10 15:25:31 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char c1, char c2, int is_c)
{
	if (c2 == 'C')
	{
		if (is_c == 1)
			return (1);
		if (is_c == 0)
		{
			if (c1 == c2)
				return (1);
			else
				return (0);
		}
	}
	if (is_c == 1)
	{
		if (c1 == c2)
			return (0);
		else
			return (1);
	}
	if (c1 == c2)
		return (1);
	return (0);
} 

int	is_end(t_coord *actual, t_coord *end)
{
	if (actual->x == end->x && actual->y == end->y)
		return (1);
	return (0);
}

static void	get_voisins_y(char **tab, t_list **list, t_coord *actual)
{
	t_list	*new;
	t_coord *tmp;

	if (tab[actual->x][actual->y + 1] != '1')
	{
		tmp = create_coord(actual->x, actual->y + 1);
		new = ft_lstnew(tmp);
		ft_lstadd_back(list, new);
	}
	if (tab[actual->x][actual->y - 1] != '1')
	{
		tmp = create_coord(actual->x, actual->y - 1);
		new = ft_lstnew(tmp);
		ft_lstadd_back(list, new);
	}
}

void	get_voisins(char **tab, t_list **voisins, t_coord *actual)
{
	t_list	*new;
	t_coord *tmp;

	if (tab[actual->x + 1][actual->y] != '1')
	{
		tmp = create_coord(actual->x + 1, actual->y);
		new = ft_lstnew(tmp);
		ft_lstadd_back(voisins, new);
	}
	if (tab[actual->x - 1][actual->y] != '1')
	{
		tmp = create_coord(actual->x - 1, actual->y);
		new = ft_lstnew(tmp);
		ft_lstadd_back(voisins, new);
	}
	get_voisins_y(tab, voisins, actual);
}
