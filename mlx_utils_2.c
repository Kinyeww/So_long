/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 21:21:35 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 21:39:02 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"
#include "ft_printf/ft_printf.h"
#include "minilibx-linux/mlx.h"

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_y = game->player_y + y;
	new_x = game->player_x + x;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
	{
		if (!check_collectible(game))
			return ;
		else
			exit_game(game);
	}
	game->player_y = new_y;
	game->player_x = new_x;
	game->move_count += 1;
	ft_printf("move count: %d\n", game->move_count);
	if (game->map[new_y][new_x] == 'C')
		collecting(game);
	else
		collecting(game);
}

void	put_image_function(t_game *g, int n, int i, int j)
{
	if (n == 1)
		mlx_put_image_to_window(g->mlx, g->win, g->wall, j * 64, i * 64);
	else if (n == 2)
		mlx_put_image_to_window(g->mlx, g->win, g->path, j * 64, i * 64);
	else if (n == 3)
		mlx_put_image_to_window(g->mlx, g->win, g->player, j * 64, i * 64);
	else if (n == 4)
		mlx_put_image_to_window(g->mlx, g->win, g->exit, j * 64, i * 64);
	else if (n == 5)
		mlx_put_image_to_window(g->mlx, g->win, g->c, j * 64, i * 64);
}

void	mapping(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				put_image_function(g, 1, i, j);
			else if (g->map[i][j] == '0')
				put_image_function(g, 2, i, j);
			else if (g->map[i][j] == 'P')
				put_image_function(g, 3, i, j);
			else if (g->map[i][j] == 'E')
				put_image_function(g, 4, i, j);
			else if (g->map[i][j] == 'C')
				put_image_function(g, 5, i, j);
			j++;
		}
		i++;
	}
}
