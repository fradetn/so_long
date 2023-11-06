#include "so_long.h"

static size_t	check_format(char **tab)
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

static int	check_char(char c1, char c2, int is_c)
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

static int	check_objs(char **tab)
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

// static int	check_path(char **tab, t_coord end)
// {

// 	return (0);
// }

int	check_map(char **tab, t_game_obj *game_obj)
{
	(void) game_obj;
	if (check_format(tab) == 1)
		return (1);
	if (check_objs(tab) == 1)
		return (1);
	return (0);
}