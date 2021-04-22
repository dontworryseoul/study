#include <stdio.h>
#include "../minilibx-linux/mlx.h"

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;

	int		img_width;
	int		img_height;

	mlx = mlx_init();

	win = mlx_new_window(mlx, 600, 400, "mlx_test_03");
	img = mlx_xpm_file_to_image(mlx, "../img/wall_n.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
	mlx_loop(mlx);
	return (0);
}
