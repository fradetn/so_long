#include "so_long.h"

int main(int argc, char **argv)
{
	void	*mlx_ptr;
	int		fd;

	if (argc != 2)

	fd = open(argv[1], O_RDONLY);
	check_map(fd);

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 300, 300, "test");
	mlx_loop(mlx_ptr);
}