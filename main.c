#include "get_next_line/get_next_line.h"
#include "So_long.h"

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

int	check_rectangular(char** map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (map[i])
	{	
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (i > 0)
		{
			if (check != j)
			{
				printf("check = %d, j = %d", check, j);
				return (0);
			}
		}
		check = j;
		i++;
	}
	printf("map is rectangular, yay :D\n");
	return (1);
}

int	map_is_walled(char** map)
{
	int i;
	int	j;
	int	one;

	one = 0;
	j = 0;
	while (map[0][j] && map[0][j] != '\n')
	{	
		if (map[0][j] == '1')
			one++;
		j++;
	}
	if (one == j)
	{
		i = 1;
		while (map[i + 1])
		{
			if (map[i][0] != '1' || map[i][one - 1] != '1')
			{
				printf("\n---%s---", map[i]);
				return (0);
			}
			i++;
		}
		j = 0;
		while (map[i][j] && j < one) //last line
		{
			if (map[i][j] != '1')
				return (0);
			j++;
		}
	}
	else
		return (0);
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

	return (1);
}

int	counter(char* filename)
{
	int	counts;
	char*	str;
	int	fd;

	counts = 0;
	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		counts++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (counts);
}

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