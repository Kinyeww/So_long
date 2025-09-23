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
	int	coin;
	void*	mlx;
}	t_game;


char**	load_map(char* filename);
int	counter(char* filename);
int	So_Long(char* filename);
int	parsing_check(char** map);
int	check_rectangular(char** map);
int	map_is_walled(char** map);
char*	getstr(char* str);
void	free_array(char** str);


#endif