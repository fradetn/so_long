/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:34:39 by nfradet           #+#    #+#             */
/*   Updated: 2023/11/23 19:12:58 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

# define CHARAC_D "./assets/brendon_down.xpm"
# define CHARAC_U "./assets/brendon_up.xpm"
# define CHARAC_L "./assets/brendon_left.xpm"
# define CHARAC_R "./assets/brendon_right.xpm"
# define ATT1 "./assets/attack2.xpm"
# define ATT2 "./assets/attack1.xpm"
# define WALL "./assets/tree.xpm"
# define GROUND "./assets/ground.xpm"
# define END "./assets/house.xpm"
# define END2 "./assets/house2.xpm"
# define COLLEC "./assets/pokeball.xpm"
# define ENN1 "./assets/draco.xpm"
# define ENN2 "./assets/draco1.xpm"
# define ENN2_1 "./assets/miaous.xpm"
# define ENN2_2 "./assets/miaous1.xpm"
# define HUD "./assets/hud.xpm"

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
	t_img	charac_down;
	t_img	charac_up;
	t_img	charac_left;
	t_img	charac_right;
	t_img	att1;
	t_img	att2;
	t_img	wall;
	t_img	ground;
	t_img	poke;
	t_img	end;
	t_img	end2;
	t_img	enn1;
	t_img	enn2;
	t_img	enn2_1;
	t_img	enn2_2;
	t_img	hud;
}	t_assets;

typedef struct s_game_obj
{
	t_list	*collecs;
	t_coord	*player;
	t_coord	*end;
	t_list	*enn1;
	t_list	*enn2;
}	t_game_obj;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_assets	assets;
	t_game_obj	game_obj;
	char		**map;
	int			nb_poke;
	int			nb_picked;
	int			nb_move;
	char		charac_ori;
	int			enn_sprite;
	int			clock;
	int			is_attacking;
	int			att_i;
}	t_data;

/*read_file.c*/
char		**file_to_tab(const char *file);
int			nb_line(int fd);
void		ft_attack_h(t_data *data, t_coord p);
void		key_move(int keycode, t_data *data);
void		ft_swap_val(char **tab, t_coord i, t_coord j);

/*items.c*/
t_list		*get_all_char(char **tab, char c);
t_coord		*create_coord(int x, int y);
t_coord		*get_char_pos(char **tab, char c);
t_game_obj	fill_objs(char **tab);
void		ft_init_data(t_data *data, char *file_name);

/*ft_free.c*/
void		ft_free(t_data *data);
void		ft_free_tab(char **tab);
void		ft_free_go(t_game_obj *go);
void		ft_free_asset(t_data *data, t_assets *assets);
void		ft_free_inv(t_data *data);

/*so_long_utils.c*/
void		aff(void *co);
void		aff_tab(char **tab);
char		**ft_tabdup(char **tab);
int			ft_tablen(char **tab);
t_img		ft_img_cpy(t_data *data, t_img *img);

/*check_map.c && check_maps_utils.c*/
size_t		check_format(char **tab);
void		get_voisins(char **tab, t_list **voisins, t_coord *actual);
int			is_end(t_coord *actual, t_coord *end);
int			check_char(char c1, char c2, int is_c);
int			check_map(t_data *data);
int			check_collecs(t_data *data, t_coord *start, t_list *collecs);
int			check_objs(char **tab);
int			is_end_near(t_list **voisins, t_coord *end);
int			check_enemies(t_data *data, t_list **enn);

/*main.c*/
int			main(int argc, char **argv);
int			ft_create_images(t_data *data);
int			close_window(t_data *data);
int			is_c_val(char c);

/*mlx_manager.c*/
void		ft_draw_charac(t_data *data, t_coord p);
void		ft_refresh(t_data *data, t_coord i);
void		ft_put_map(t_data *data);
int			ft_init_mlx(t_data *data);
void		draw_transparency(t_data *data, t_img img, t_coord c);
void		ft_put_image(t_data *data, t_img img, t_coord i);

/*player_mvt.c*/
int			key_hook(int keycode, t_data *data);
void		ft_attack(t_data *data);
int			ft_move(t_data *data, int x, int y);
void		ft_action(t_data *data, t_coord move);
int			move_valid(t_data *data, t_coord move);

#endif