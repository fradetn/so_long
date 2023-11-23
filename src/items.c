/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:34:00 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/22 19:07:51 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coord	*create_coord(int x, int y)
{
	t_coord	*coord;

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
t_list	*get_all_char(char **tab, char c)
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
			if (tab[x][y] == c)
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

t_game_obj	fill_objs(char **tab)
{
	t_game_obj	game_obj;

	game_obj.collecs = get_all_char(tab, 'C');
	game_obj.player = get_char_pos(tab, 'P');
	game_obj.end = get_char_pos(tab, 'E');
	game_obj.enn1 = get_all_char(tab, '2');
	game_obj.enn2 = get_all_char(tab, '3');
	return (game_obj);
}

void	ft_init_data(t_data *data, char *file_name)
{
	data->map = file_to_tab(file_name);
	data->game_obj = fill_objs(data->map);
	data->nb_poke = 0;
	data->nb_picked = 0;
	data->nb_move = 0;
	data->enn_sprite = 0;
	data->clock = 0;
	data->att_i = 0;
	data->is_attacking = 0;
	data->charac_ori = 'd';
}
