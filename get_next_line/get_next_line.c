/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:31:53 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/10/31 16:02:03 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_leftovers(char *saves)
{
	int		i;
	char	*leftovers;

	if (!saves)
		return (NULL);
	i = 0;
	while (saves[i] && saves[i] != '\n')
		i++;
	if (saves[i] == '\n' && saves[i + 1])
	{
		leftovers = ft_substr_all(saves, i + 1);
		return (leftovers);
	}
	return (NULL);
}

char	*ft_one_line(char *saves)
{
	int		i;
	int		k;
	char	*one_line;

	if (!saves)
		return (NULL);
	i = 0;
	while (saves[i] && saves[i] != '\n')
		i++;
	if (saves[i] == '\n')
		i++;
	one_line = malloc(sizeof(char) * (i + 1));
	if (!one_line)
		return (NULL);
	k = 0;
	while (k < i)
	{
		one_line[k] = saves[k];
		k++;
	}
	one_line[k] = '\0';
	return (one_line);
}

char	*read_and_join(int fd, char *saves)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		saves = ft_strjoin(saves, buffer);
		if (!saves)
			return (NULL);
		if (ft_strchr(saves, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(saves);
		return (NULL);
	}
	return (saves);
}

char	*get_next_line(int fd)
{
	char		*saves;
	static char	*leftovers;
	char		*newline;
	char		*result;

	saves = NULL;
	if (leftovers)
	{
		saves = ft_strdup(leftovers);
		free(leftovers);
		leftovers = NULL;
	}
	saves = read_and_join(fd, saves);
	if (!saves || *saves == '\0')
	{
		free(saves);
		return (NULL);
	}
	newline = ft_strchr(saves, '\n');
	if (newline && *(newline + 1) != '\0')
		leftovers = save_leftovers(saves);
	result = ft_one_line(saves);
	free(saves);
	return (result);
}
