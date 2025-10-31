/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:21:29 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 21:21:30 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"
#include "minilibx-linux/mlx.h"

void	exit_game(t_game *game)
{
	int	x;

	x = 0;
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
	exit(0);
}

void	locate_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

int	cal_size(char **map, int size, char cord)
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

int	render(t_game *game)
{
	if (game->map != NULL)
		mapping(game);
	return (0);
}

int	open_window(t_game *game)
{
	image_loader(game);
	render(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
