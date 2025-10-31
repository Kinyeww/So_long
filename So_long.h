/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:12:04 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 21:39:55 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef PIXEL
#  define PIXEL 64

# endif

typedef struct s_long
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	void	*wall;
	void	*player;
	void	*path;
	void	*exit;
	void	*c;
	char	**map;
	int		player_x;
	int		player_y;
	int		move_count;
}	t_game;

char	**load_map(char *filename);
int		map_content(char **map);
int		counter(char *filename);
int		So_Long(char *filename);
int		parsing_check(char **map);
int		check_rectangular(char **map);
int		map_is_walled(char **map);
int		winnable(char **map);
int		find_p(char **str, int *pos_i, int *pos_j);
int		check_c(char **map);
char	**copy_map(char **map);
char	*getstr(char *str);
void	free_array(char **str);
int		initiate_minilibx(char **map);
void	image_loader(t_game *g);
int		open_window(t_game *game);
void	mapping(t_game *game);
int		render(t_game *game);
int		key_hook(int keycode, t_game *game);
void	free_arr(char **array);
void	move_player(t_game *game, int x, int y);
void	locate_player(t_game *game);
void	update_map(t_game *game);
void	put_image_function(t_game *g, int n, int i, int j);
void	exit_game(t_game *game);
int		cal_size(char **map, int size, char cord);
void	collecting(t_game *game);
int		check_collectible(t_game *game);

#endif
