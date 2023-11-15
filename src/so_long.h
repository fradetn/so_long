/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:34:39 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/15 17:32:50 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define CHARAC "./assets/brendon.xpm"
# define WALL "./assets/tree.xpm"
# define GROUND "./assets/ground.xpm"
# define END "./assets/house.xpm"
# define COLLEC "./assets/pokeball.xpm"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	void	*img_ptr;
    char	*data;
	int		w;
	int		h;
	int		bpp;
    int		size_line;
    int		endian;
}	t_img;

typedef struct s_assets
{
	t_img	character;
	t_img	wall;
	t_img	ground;
	t_img	poke;
	t_img	end;
}	t_assets;

typedef struct s_game_obj
{
	t_list	*collecs;
	t_coord	*player;
	t_coord	*end;
}	t_game_obj;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_assets	assets;
	t_data		game_obj;
	char		**map;
}	t_data;




/*read_file.c*/
char		**file_to_tab(const char *file);
int			nb_line(int fd);

/*items.c*/
t_list		*get_all_collec(char **tab);
t_coord		*create_coord(int x, int y);
t_coord		*get_char_pos(char **tab, char c);
t_game_obj	*fill_objs(char **tab);

/*ft_free.c*/
void		ft_free(char **tab, t_game_obj *go);
void		ft_free_tab(char **tab);
void		ft_free_coord(void *coord);

/*so_long_utils.c*/
void		aff(void *co);
void		aff_tab(char **tab);
char		**ft_tabdup(char **tab);
int			ft_tablen(char **tab);

/*check_map.c && check_maps_utils.c*/
size_t	check_format(char **tab);
void	get_voisins(char **tab, t_list **voisins, t_coord *actual);
int		is_end(t_coord *actual, t_coord *end);
int		check_char(char c1, char c2, int is_c);
int		check_map(char **tab, t_game_obj *game_obj);
int		check_collecs(char **tab, t_coord *start, t_list *collecs);
int		check_path(char **tab, t_coord *actual ,t_coord *end);
int		check_objs(char **tab);

/*main.c*/
int			main(int argc, char **argv);
int			ft_init_mlx(t_data *data, char **tab);
int			ft_create_images(t_data *data);
void		ft_put_map(t_data *data, char **tab);
int			key_hook(int keycode, t_data *data);

#endif