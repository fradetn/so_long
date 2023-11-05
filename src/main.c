#include "so_long.h"

void ft_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

int main(int argc, char **argv)
{
	// void	*mlx_ptr;
	char	**tab;
	char	*file_name;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	tab = file_to_tab(file_name);
	if (check_map(tab) == 1)
	{
		ft_printf("La map fournie est invalide !");
		ft_free(tab);
		free(file_name);
		return (1);
	}

	// fd = open(file_name, O_RDONLY);
	// mlx_ptr = mlx_init();
	// mlx_new_window(mlx_ptr, 300, 300, "test");
	// mlx_loop(mlx_ptr);

	free(file_name);
	ft_free(tab);
}