/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:39:46 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 18:42:03 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "So_long.h"

void	fill(char **check_map, int pos_i, int pos_j)
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

int	check_win(char **check, int i, int j)
{
	i = 0;
	while (check[i])
	{
		j = 0;
		while (check[i][j])
		{
			if (check[i][j] == 'C' || check[i][j] == 'E')
			{
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

int	winnable(char **map)
{
	int		i;
	int		j;
	char	**check;

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
	if (!check_win(check, i, j))
		return (0);
	return (1);
}

char	**load_map(char *filename)
{
	char	**str;
	int		fd;
	int		lines;
	int		i;

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
