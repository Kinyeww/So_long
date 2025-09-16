git p/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckin-yew <ckin-yew@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:31:53 by ckin-yew          #+#    #+#             */
/*   Updated: 2025/06/14 21:54:13 by ckin-yew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_leftovers(char *saves)
{
	int		i;
	char	*temp_leftovers;

	if (!saves)
		return (NULL);
	i = 0;
	while (saves[i] != '\n' && saves[i])
		i++;
	if (saves[i + 1] && saves[i] == '\n')
	{
		temp_leftovers = ft_substr_all(saves, i + 1);
		return (temp_leftovers);
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

char	*ft_read_join(char *saves, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
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
		free (buffer);
		return (NULL);
	}
	free (buffer);
	return (saves);
}

char	*ft_checksaves(char *saves)
{
	if (!saves || *saves == '\0')
	{
		free (saves);
		return (NULL);
	}
	return (saves);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*saves;
	static char	*leftovers;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saves = NULL;
	if (leftovers)
	{
		saves = ft_strdup(leftovers);
		free (leftovers);
		leftovers = NULL;
	}
	saves = ft_read_join(saves, fd);
	if (!ft_checksaves(saves))
		return (NULL);
	newline = ft_strchr(saves, '\n');
	if (newline && *(newline + 1) != '\0')
		leftovers = ft_save_leftovers(saves);
	result = ft_one_line(saves);
	free (saves);
	return (result);
}
