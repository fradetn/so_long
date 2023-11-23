/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:39:27 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/22 19:30:53 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aff(void *co)
{
	ft_printf("(%d, %d)\n", ((t_coord *)co)->x, ((t_coord *)co)->y);
}

void	aff_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

char	**ft_tabdup(char **tab)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * (ft_tablen(tab) + 1));
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

t_img	ft_img_cpy(t_data *data, t_img *img)
{
	t_img	cpy;

	cpy.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
	GROUND, &cpy.w, &cpy.h);
	cpy.data = mlx_get_data_addr(cpy.img_ptr, &cpy.bpp, \
	&cpy.size_line, &cpy.endian);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, \
	&img->size_line, &img->endian);
	return (cpy);
}
