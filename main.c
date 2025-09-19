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
	int	player;
	int	exit;
	int	collectible;

	i = 1;
	player = 0;
	exit = 0;
	collectible = 0;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	printf("player = %d, c = %d, exit = %d\n", player, collectible, exit);
	printf("i = %d, j = %d\n", i, j);
	if (player != 1 || exit != 1 || collectible < 1)
		return (0);
	return (1);
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
		printf("not rectangle ah noob\n");
		return (0);
	}
	printf("check 1 = map is rectangular, yay :D\n");
	if (!(map_is_walled(map)))
	{
		printf("map not surrounded by walls sohai\n");
		return (0);
	}
	printf("check 2 = woohoo map is surrounded by walls!!! Good Job!!\n");
	if (!(map_content(map)))
	{
		printf("map dont have enough content AHHHHHHH WHATT TO PLAYYY\n");
		return (0);
	}
	printf("check 3 = letss go you have enough content to play dyyy!!! :DDDD\n");
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