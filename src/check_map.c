/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:07:20 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/15 23:59:17 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	check_format(char **tab)
{
	size_t		len;
	size_t		i;
	size_t		j;

	i = 0;
	len = ft_strlen(tab[0]);	

	while (tab[i])
	{
		if (ft_strlen(tab[i]) != len)
			return (1);
		if (tab[i][0] != '1' || tab[i][len - 1] != '1')
			return (1);
		if (i == 0 || tab[i + 1] == NULL)
		{
			j = 0;
			while (tab[i][j])
			{
				if (tab[i][j++] != '1')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int	check_objs(char **tab)
{
	int	x;
	int	y;
	int	is_p;
	int	is_e;
	int	is_c;

	x = 0;
	is_e = 0;
	is_p = 0;
	is_c = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			is_p = check_char(tab[x][y], 'P', is_p);
			is_e = check_char(tab[x][y], 'E', is_e);
			is_c = check_char(tab[x][y], 'C', is_c);
			y++;
		}
		x++;
	}
	if (is_c == 1 && is_e == 1 && is_p == 1)
		return (0);
	return (1);
}

int	check_path(char **tab, t_coord *actual ,t_coord *end)
{
	t_list **head;
	t_list *voisins;
	t_list *tmp;

	voisins = NULL;
	get_voisins(tab, &voisins, actual);
	if (voisins)
	{
		head = &voisins;
		tmp = voisins;
	}
	while (is_end(actual, end) != 1 && tmp != NULL)
	{
		tab[actual->x][actual->y] = '1';
		actual = tmp->content;
		get_voisins(tab, &voisins, actual);
		tmp = tmp->next;
	}
	if (is_end(actual, end) && head)
	{
		ft_lstclear(head, &ft_free_coord);
		return (0);
	}
	ft_lstclear(head, &ft_free_coord);
	return (1);
}

int	check_collecs(t_data *data, t_coord *start, t_list *collecs)
{
	char	**cpy;

	while (collecs)
	{
		cpy = ft_tabdup(data->map);
		cpy[data->game_obj.end->x][data->game_obj.end->y] = '1';
		if (check_path(cpy, start, collecs->content) == 1)
		{
			ft_printf("Le joueur ne peut pas atteindre un collectible !\n");
			ft_free_tab(cpy);
			return (1);
		}
		ft_free_tab(cpy);
		collecs = collecs->next;
	}
	return (0);
}

int	check_map(t_data *data)
{
	char	**cpy;

	if (check_format(data->map) == 1)
	{
		ft_printf("Le format de la map est invalide !\n");
		return (1);
	}
	if (check_objs(data->map) == 1)
	{
		ft_printf("La map ne contient pas les objets demandes !\n");
		return (1);
	}
	cpy = ft_tabdup(data->map);
	if (check_path(cpy, data->game_obj.player, data->game_obj.end) == 1)
	{
		ft_printf("Le joueur ne peut pas atteindre la sortie !\n");
		ft_free_tab(cpy);
		return (1);
	}
	ft_free_tab(cpy);
	if (check_collecs(data, data->game_obj.player, 
	data->game_obj.collecs) == 1)
		return (1);
	return (0);
}
