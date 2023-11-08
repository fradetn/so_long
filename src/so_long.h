#ifndef SO_LONG_H
#define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct	s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct	s_game_obj
{
	t_list	*collecs;
	t_coord	*player;
	t_coord	*end;
}	t_game_obj;

int 		main(int argc, char **argv);
int			check_map(char **tab, t_game_obj *game_obj);
int			nb_line(int fd);
char		**file_to_tab(const char *file);
char		**ft_tabdup(char **tab);
void		ft_free(char **tab, t_game_obj *go);
void		ft_free_tab(char **tab);
void		ft_free_coord(void *coord);
t_coord		*create_coord(int x, int y);
t_list		*get_all_collec(char **tab);
t_coord		*get_char_pos(char **tab, char c);
t_game_obj	*fill_objs(char **tab);
void 		aff(void *co);
void 		aff_tab(char **tab);

int	check_path(char **tab, t_coord *actual ,t_coord *end);	

#endif