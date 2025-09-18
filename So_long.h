#ifndef SO_LONG_H
	#define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char**	load_map(char* filename);
int	counter(char* filename);
int	So_Long(char* filename);
int	parsing_check(char** map);
int	check_rectangular(char** map);
int	map_is_walled(char** map);


#endif