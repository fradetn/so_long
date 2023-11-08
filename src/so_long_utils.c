#include "so_long.h"

int	ft_tablen(char **tab)
{
	int len;

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