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
	int	valid;
}	t_game;

typedef struct s_assets
{
	void	*wall;
	void	*player;
	void	*path;
	void	*exit;
	void	*c;
	int	valid;
}	t_assets;

char**	load_map(char* filename);
int	counter(char* filename);
int	So_Long(char* filename);
int	parsing_check(char** map);
int	check_rectangular(char** map);
int	map_is_walled(char** map);
char*	getstr(char* str);
void	free_array(char** str);
t_game	initiate_minilibx(char** map);
t_assets	image_loader(t_game g);
void	open_window(t_game game);


#endif