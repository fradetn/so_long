#ifndef SO_LONG_H
#define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

int 	main(int argc, char **argv);
int		check_map(char **tab);
int		nb_line(int fd);
char	**file_to_tab(const char *file);


#endif