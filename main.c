#include "get_next_line/get_next_line.h"
#include "So_long.h"

int find_p(char** str, int* pos_i, int* pos_j)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				*pos_i = i;
				*pos_j = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_c(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	fill(char** check_map, int pos_i, int pos_j)
{
	if (pos_i < 0 || (!(check_map[pos_i])))
		return ;
	if (pos_j < 0 || (!(check_map[pos_i][pos_j])))
		return ;
	if (check_map[pos_i][pos_j] == '1' || check_map[pos_i][pos_j] == 'X')
		return ;
	if (check_map[pos_i][pos_j] == 'E' && !check_c(check_map))
		return ;
	check_map[pos_i][pos_j] = 'X';
	fill(check_map, pos_i + 1, pos_j);
	fill(check_map, pos_i, pos_j + 1);
	fill(check_map, pos_i - 1, pos_j);
	fill(check_map, pos_i, pos_j - 1);
}

char** copy_map(char** map)
{
	int	i;
	char**	tmp;

	i = 0;
	while (map[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (map[i])
	{
		tmp[i] = getstr(map[i]);
		if (tmp[i] == NULL)
			return (NULL);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char*	getstr(char* str)
{
	int	i;
	char*	tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '\n'
			&& str[i] != 'P' && str[i] != 'E' && str[i] != 'C')
		{
			printf("invalid string = %s", str);
			return (NULL);
		}
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	winnable(char** map)
{
	int	i;
	int	j;
	char** check;

	i = 0;
	j = 0;
	check = copy_map(map);
	if (check == NULL)
	{
		free_array(check);
		return (0);
	}
	find_p(map, &i, &j);
	fill(check, i, j);
	i = 0;
	while (check[i])
	{
		j = 0;
		while (check[i][j])
		{
			if (check[i][j] == 'C' || check[i][j] == 'E')
			{
				printf ("\nfailed floodfill[%d][%d] = %s", i, j, check[i]);
				free_array(check);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_array(check);
	return (1);
}

void	free_array(char **array)
{
	int	x;
	
	x = 0;
	if (!array)
		return ;
	while (array[x])
	{
		free(array[x]);
		x++;
	}
	free(array);
}

char	**load_map(char* filename)
{
	char	**str;
	int	fd;
	int	lines;
	int	i;

	lines = counter(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || lines < 3)
		return (NULL);
	str = malloc(sizeof(char *) * (lines + 1));
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
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collectible < 1)
		return (0);
	return (1);
}

int	main(int ac, char **filename)
{
	char**	map;

	if (ac == 2)
	{
		map = load_map(filename[1]);
		if ( !map || !(parsing_check(map)))
		{
			printf("---parsing failed---\n");
			return (1);
		}
		if (!(initiate_minilibx(map)))
		{
			printf("intiating minilibx");
			free_array(map);
			printf("minilibx shutting down");
		}
	}
	return (0);
}

int	parsing_check(char **map)
{
	if (!(check_rectangular(map)))
	{
		free_array(map);
		printf("map not rectangle ah noob\n");
		return (0);
	}
	printf("check 1 = map is rectangular, yay :D\n");
	if (!(map_is_walled(map)))
	{
		free_array(map);
		printf("map not surrounded by walls sohai\n");
		return (0);
	}
	printf("check 2 = woohoo map is surrounded by walls!!! Good Job!!\n");
	if (!(map_content(map)))
	{
		free_array(map);
		printf("map dont have enough content AHHHHHHH WHATT TO PLAYYY\n");
		return (0);
	}
	printf("check 3 = letss go you have enough content to play dyyy!!! :DDDD\n");
	if (!(winnable(map)))
	{
		free_array(map);
		printf("why create a map that you couldn't win smh, you think you can hack issit\n");
		return (0);
	}
	printf("all done broski, goodjob on submitting a valid map ;)\n\n");
	printf("---P A R S I N G---S U C C E S S---");
	return (1);
}
