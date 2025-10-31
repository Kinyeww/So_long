#ifndef SO_LONG_H
	#define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef PIXEL
	#define PIXEL 64

#endif

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

char**	load_map(char *filename);
int	counter(char *filename);
int	So_Long(char *filename);
int	parsing_check(char **map);
int	check_rectangular(char **map);
int	map_is_walled(char **map);
char	*getstr(char *str);
void	free_array(char **str);
int	initiate_minilibx(char **map);
void	image_loader(t_game *g);
int	open_window(t_game *game);
void	mapping(t_game *game);
int	render(t_game *game);
int	key_hook(int keycode, t_game *game);
void	free_arr(char **array);
void	move_player(t_game *game, int x, int y);
void	locate_player(t_game *game);
void	update_map(t_game *game);

#endif