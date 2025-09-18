#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

static char**	load_map(char* filename);


int	So_Long(char* filename)
{
	char**	map;
	int	i;

	map = load_map(filename);
	i = 0;
	printf("hi");
	while (map[i])
	{
		printf("inside");
		printf("Row = %s", map[i]);
		i++;
	}
	return (1);
}

static int	counter(int fd)
{
	int	counts;
	char*	str;

	counts = 0;
	str = get_next_line(fd);
	while (str)
	{
		counts++;
		free(str);
		str = get_next_line(fd);
	}
	return (counts);
}

char**	load_map(char* filename)
{
	char**	str;
	int	fd;
	int	lines;
	int	i;

	fd = open(filename, O_RDONLY);
	lines = counter(fd);
	str = malloc(sizeof(char *) * lines);
	if (!str)
		return (NULL);
	while (i < lines)
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	close(fd);
	return (str);
}

int	main(void)
{
	if ((!So_Long("map.ber")))
	{
		printf("error\n");
		return (1);
	}
	else
		printf("else");
	return (0);
}