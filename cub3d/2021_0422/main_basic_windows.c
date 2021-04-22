#include "../minilibx-linux/mlx.h"

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "widow_test");
	mlx_loop(mlx);
}
