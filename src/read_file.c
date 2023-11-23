/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:37:59 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/22 19:35:36 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_line(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (len);
}

char	**file_to_tab(const char *file)
{
	char	**tab;
	char	*line;
	int		len;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	len = nb_line(fd);
	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		line = get_next_line(fd);
		tab[i] = ft_strdup_no_nl(line);
		free(line);
		i++;
	}
	tab[i] = 0;
	close(fd);
	return (tab);
}

void	ft_swap_val(char **tab, t_coord i, t_coord j)
{
	char	tmp;

	tmp = tab[i.x][i.y];
	tab[i.x][i.y] = tab[j.x][j.y];
	tab[j.x][j.y] = tmp;
}

void	key_move(int keycode, t_data *data)
{
	if (keycode == 122)
	{
		data->charac_ori = 'u';
		ft_move(data, -1, 0);
	}
	else if (keycode == 115)
	{
		data->charac_ori = 'd';
		ft_move(data, 1, 0);
	}
	else if (keycode == 113)
	{
		data->charac_ori = 'l';
		ft_move(data, 0, -1);
	}
	else if (keycode == 100)
	{
		data->charac_ori = 'r';
		ft_move(data, 0, 1);
	}
}

void	ft_attack_h(t_data *data, t_coord p)
{
	if (data->map[p.x][p.y + 1] == '2' || data->map[p.x][p.y + 1] == '3')
	{
		data->nb_picked--;
		data->is_attacking = 1;
		data->map[p.x][p.y + 1] = '0';
		p.y += 1;
	}
	else if (data->map[p.x][p.y - 1] == '2' || data->map[p.x][p.y - 1] == '3')
	{
		data->nb_picked--;
		data->is_attacking = 1;
		data->map[p.x][p.y - 1] = '0';
		p.y -= 1;
	}
}
