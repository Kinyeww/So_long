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

int	escape_game(t_game *game)
{
	free(game);
	return (0);
}

void	initiate_minilibx(char **map)
{
	int		width;
	int		height;
	t_game	game;

	width = cal_size(map, PIXEL, 'x');
	height = cal_size(map, PIXEL, 'y');
	game.map = map;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, width, height, "so_long");
	open_window(&game);
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

void	open_window(t_game *game)
{
	printf("opening window\n");
	image_loader(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_loop(game->mlx);
}

int	key_hook(int keycode, t_game *game)
{
	printf("Keycode %d\n", keycode);
	if (keycode == XK_w)
		printf("fuck u");
	else if (keycode == XK_a)
		printf("fuck him");
	else if (keycode == XK_s)
		printf("fuck them");
	else if (keycode == XK_d)
		printf("fuck me");
	else if (keycode == XK_Escape)
	{
		printf("heheheha grrrrr");
		escape_game(game);
	}
	return (0);
}

int	render(t_game *game)
{
	mapping(game);
	return (0);
}

void	mapping(t_game *game)
{
	int	i;
	int	j;
	char	**map;

	map = game->map; 
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, j * 64, i * 64);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->path, j * 64, i * 64);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player, j * 64, i * 64);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, j * 64, i * 64);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->c, j * 64, i * 64);
			j++;
		}
		i++;
	}
}