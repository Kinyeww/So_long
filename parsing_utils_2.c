/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:28:28 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 19:20:34 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

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

char	*getstr(char *str)
{
	int		i;
	char	*tmp;

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
			return (NULL);
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**copy_map(char **map)
{
	int		i;
	char	**tmp;

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

int	find_p(char **str, int *pos_i, int *pos_j)
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
