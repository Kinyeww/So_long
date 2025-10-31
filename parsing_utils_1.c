/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:39:14 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 16:39:15 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"
#include "get_next_line/get_next_line.h"

static void	check_content(char c, int *player, int *exit, int *collectible);

int	counter(char *filename)
{
	int		counts;
	char	*str;
	int		fd;

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

int	map_is_walled(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[0][j] && map[0][j] != '\n')
		j++;
	while (map[i + 1])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
		{
			printf("\n---%s---", map[i]);
			return (0);
		}
		i++;
	}
	j = 0;
	while (map[i][j + 1])
	{
		if (map[i][j] != '1' || map[0][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_rectangular(char **map)
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
				printf("check = %d, j = %d\n", check, j);
				return (0);
			}
		}
		check = j;
		i++;
	}
	return (1);
}

int	map_content(char **map)
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
			if (map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == 'C')
				check_content(map[i][j], &player, &exit, &collectible);
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collectible < 1)
		return (0);
	return (1);
}

static void	check_content(char c, int *player, int *exit, int *collectible)
{
	if (c == 'P')
		*(player) += 1;
	else if (c == 'E')
		*(exit) += 1;
	else if (c == 'C')
		*(collectible) += 1;
	return ;
}
