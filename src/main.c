#include "so_long.h"

void	ft_free(char **tab, t_game_obj *go)
{
	int i;

	i = 0;
	free(go->end);
	free(go->player);
	ft_lstclear(&(go->collecs), &ft_free_coord);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_free_coord(void *coord)
{
	free(coord);
}

t_game_obj	*fill_objs(char **tab)
{
	t_game_obj *game_obj;

	game_obj = (t_game_obj *)malloc(sizeof(t_game_obj));
	if (!game_obj)
		return (NULL);
	game_obj->collecs = get_all_collec(tab);
	game_obj->player = get_char_pos(tab, 'P');
	game_obj->end = get_char_pos(tab, 'E');
	return (game_obj);
}

void aff(void *co)
{
	ft_printf("(%d, %d)\n", ((t_coord *)co)->x, ((t_coord *)co)->y);
}

int main(int argc, char **argv)
{
	// void	*mlx_ptr;
	char		**tab;
	char		*file_name;
	t_game_obj	*game_obj;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	tab = file_to_tab(file_name);
	game_obj = fill_objs(tab);
	if (check_map(tab, game_obj) == 1)
	{
		ft_printf("La map fournie est invalide !");
		ft_free(tab, game_obj);
		free(file_name);
		return (1);
	}
	// ft_lstiter(game_obj->collecs, &aff);

	// fd = open(file_name, O_RDONLY);
	// mlx_ptr = mlx_init();
	// mlx_new_window(mlx_ptr, 300, 300, "test");
	// mlx_loop(mlx_ptr);

	free(file_name);
	ft_free(tab, game_obj);
} 

/* int main(int argc, char **argv)
{
	// void	*mlx_ptr;
	char		**tab;
	char		*file_name;
	// t_game_obj	game_obj;

	(void) argc;
	file_name = ft_strjoin("maps/", argv[1]);

	tab = file_to_tab(file_name);
	ft_printf("%d",check_objs(tab));
	free(file_name);
	ft_free(tab);
}  */