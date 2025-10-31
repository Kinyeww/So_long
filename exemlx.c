/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:15:49 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 21:42:36 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"
#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>

int	initiate_minilibx(char **map)
{
	int		width;
	int		height;
	t_game	game;

	width = cal_size(map, PIXEL, 'x');
	height = cal_size(map, PIXEL, 'y');
	game.map = map;
	locate_player(&game);
	game.move_count = 0;
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.win = mlx_new_window(game.mlx, width, height, "so_long");
	if (!(open_window(&game)))
		return (0);
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

int	check_collectible(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	collecting(t_game *game)
{
	int	old_y;
	int	old_x;

	old_y = 0;
	while (game->map[old_y])
	{
		old_x = 0;
		while (game->map[old_y][old_x])
		{
			if (game->map[old_y][old_x] == 'P')
			{
				game->map[game->player_y][game->player_x] = 'P';
				game->map[old_y][old_x] = '0';
				return ;
			}
			old_x++;
		}
		old_y++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_w)
		move_player(game, 0, -1);
	else if (keycode == XK_a)
		move_player(game, -1, 0);
	else if (keycode == XK_s)
		move_player(game, 0, 1);
	else if (keycode == XK_d)
		move_player(game, 1, 0);
	else if (keycode == XK_Escape)
		exit_game(game);
	render(game);
	return (0);
}
