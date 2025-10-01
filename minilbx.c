#include "So_long.h"
#include "minilibx-linux/mlx.h"

static int	cal_size(char **map, int size, char cord)
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

t_game	initiate_minilibx(char **map)
{
	void	*win;
	int		width;
	int		height;
	t_game	game;

	width = cal_size(map, PIXEL, 'x');
	height = cal_size(map, PIXEL, 'y');
	game.valid = 1;
	game.mlx = mlx_init();
	if (!game.mlx)
		game.valid = 0;
	game.win = mlx_new_window(game.mlx, width, height, "so_long");
	open_window(game);
}

t_assets	image_loader(t_game g)
{
	int			img_w;
	int			img_h;
	t_assets	asset;

	asset.valid = 1;
	asset.wall = mlx_xpm_file_to_image(g.mlx, "asset/wall.xpm", &img_w, &img_h);
	asset.player = mlx_xpm_file_to_image(g.mlx, "asset/player.xpm", &img_w, &img_h);
	asset.exit = mlx_xpm_file_to_image(g.mlx, "asset/exit.xpm", &img_w, &img_h);
	asset.path = mlx_xpm_file_to_image(g.mlx, "asset/path.xpm", &img_w, &img_h);
	asset.c = mlx_xpm_file_to_image(g.mlx, "asset/collectible.xpm", &img_w, &img_h);
	if (!asset.wall || !asset.player || !asset.exit || !asset.path || !asset.c)
		asset.valid = 0;
	return (asset);
}

void	open_window(t_game game)
{
	t_assets	asset;

	asset = image_loader(game);
	if (asset.valid == 0)
		return ;
	mlx_put_image_to_window(game.mlx, game.win, asset.wall, 1, 1);
	mlx_loop(game.mlx);
}