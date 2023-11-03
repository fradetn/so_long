#include "so_long.h"

int main()
{
	void	*mlx_ptr;
	// void	*win;

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 300, 300, "test");
}