/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:37:59 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/08 07:38:12 by nfradet          ###   ########.fr       */
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
