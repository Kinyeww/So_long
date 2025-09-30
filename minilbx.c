#include "So_long.h"
#include "minilibx-linux/mlx.h"

static int	cal_size(char** map, int size, char cord)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (cord == 'x')
	{
		while (map[0][x])
			x++;
		return (x * size);
	}
	while (map[y])
		y++;
	return (y * size);
}

int	initiate_minilibx(char** map)
{
	void    *win;
	int     width;
	int     height;
	t_game	solong;

	width = cal_size(map, PIXEL, 'x');
	height = cal_size(map, PIXEL, 'y');
	solong.mlx = mlx_init();
	if (!solong.mlx)
		return (1); // handle error
	win = mlx_new_window(solong.mlx, width, height, "so_long");
}

int	image_loader(void)
{
	void    *wall;
	int     img_w;
	int     img_h;
	t_game	solong;

	wall = mlx_xpm_file_to_image(solong.mlx, "wall.xpm", &img_w, &img_h);
	if (!wall)
		return (1); // handle error
}