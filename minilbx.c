#include "So_long.h"
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>

static int	cal_size(char **map, int size, char cord)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (cord == 'x')
	{
		while (map[0][x] && map[0][x] != '\n')
			x++;
		return (x * size);
	}
	while (map[y])
		y++;
	return (y * size);
}

int	initiate_minilibx(char **map)
{
	int		width;
	int		height;
	t_game	game;

	width = cal_size(map, PIXEL, 'x');
	height = cal_size(map, PIXEL, 'y');
	game.map = map;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.win = mlx_new_window(game.mlx, width, height, "so_long");
	if (!(open_window(&game)))
		return (0);
	return (1);
}

int	exit_game(t_game *game)
{
	int	x;

	x = 0;
	printf("exiting\n");
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	mlx_destroy_image(game->mlx, game->c);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->path);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	printf("exit done\n");
	return (1);
}

void	image_loader(t_game *g)
{
	int			img_w;
	int			img_h;

	g->wall = mlx_xpm_file_to_image(g->mlx, "asset/wall.xpm", &img_w, &img_h);
	g->player = mlx_xpm_file_to_image(g->mlx, "asset/player.xpm", &img_w, &img_h);
	g->exit = mlx_xpm_file_to_image(g->mlx, "asset/exit.xpm", &img_w, &img_h);
	g->path = mlx_xpm_file_to_image(g->mlx, "asset/path.xpm", &img_w, &img_h);
	g->c = mlx_xpm_file_to_image(g->mlx, "asset/collectible.xpm", &img_w, &img_h);
}

int	open_window(t_game *game)
{
	printf("opening window\n");
	image_loader(game);
	render(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_w)
		printf("fuck u\n");
	else if (keycode == XK_a)
		printf("fuck him\n");
	else if (keycode == XK_s)
		printf("fuck them\n");
	else if (keycode == XK_d)
		printf("fuck me\n");
	else if (keycode == XK_Escape)
	{
		exit_game(game);
		printf("mlx: %p, win: %p\n", game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	render(t_game *game)
{
	if (game->map != NULL)
		mapping(game);
	return (0);
}

void	mapping(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->path, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->c, j * 64, i * 64);
			j++;
		}
		i++;
	}
}