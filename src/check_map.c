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

int	check_path(char **tab)
{
	
}

int	check_map(char **tab)
{
	if (check_format(tab) == 1)
		return (1);

	return (0);
}