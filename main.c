#include "get_next_line/get_next_line.h"
#include "So_long.h"

char**	load_map(char* filename)
{
	char**	str;
	int	fd;
	int	lines;
	int	i;

	lines = counter(filename);
	fd = open(filename, O_RDONLY);
	str = malloc(sizeof(char *) * lines);
	if (!str)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	close(fd);
	return (str);
}

int	map_content(char** map)
{
	int	i;
	int	j;
	int	content;

	i = 1;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ''
	}
}

int	So_Long(char* filename)
{
	char**	map;

	map = load_map(filename);
	if (!(parsing_check(map)))
	{
		printf("parsing failed");
		return (0);
	}
	return (1);
}

int	parsing_check(char** map)
{
	if (!(check_rectangular(map)))
	{
		printf("not rectangle ah noob");
		return (0);
	}
	if (!(map_is_walled(map)))
	{
		printf("map not surrounded by walls sohai");
		return (0);
	}
	if (!(map_content(map)))
	{
		printf("map dont have enough content AHHHHHHH");
		return (0);
	}
	return (1);
}

int	main(void)
{
	if ((!So_Long("map.ber")))
	{
		printf("error\n");
		return (1);
	}
	else
		printf("so far so good :) keep it up!!!");
	return (0);
}