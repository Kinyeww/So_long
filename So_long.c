/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:24:27 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 21:41:24 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"
#include "ft_printf.h"

int	main(int ac, char **filename)
{
	char	**map;

	if (ac == 2)
	{
		map = load_map(filename[1]);
		if (!map || !(parsing_check(map)))
		{
			ft_printf("error\n");
			return (1);
		}
		if (!(initiate_minilibx(map)))
			free_array(map);
	}
	return (0);
}

int	parsing_check(char **map)
{
	if (!(check_rectangular(map)))
	{
		printf("failed 1");
		free_array(map);
		return (0);
	}
	if (!(map_is_walled(map)))
	{
		printf("failed 2");
		free_array(map);
		return (0);
	}
	if (!(map_content(map)))
	{
		printf("failed 3");
		free_array(map);
		return (0);
	}
	if (!(winnable(map)))
	{
		printf("failed 4");
		free_array(map);
		return (0);
	}
	return (1);
}
