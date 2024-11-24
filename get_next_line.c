/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:10:18 by ael-majd          #+#    #+#             */
/*   Updated: 2024/11/24 19:04:37 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_line(int fd, char *rest)
{
	int		byte_read;
	char	*buffer;
	char	*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_read] = '\0';
		temp = rest;
		rest = ft_strjoin(rest, buffer);
		free(temp);
		temp = NULL;
		if (find_newline(rest) >= 0)
			break ;
	}
	free(buffer);
	return (rest);
}

char	*getting_line(char *rest)
{
	char	*line;
	int		new_index;

	new_index = find_newline(rest);
	if (new_index < 0)
		return (ft_strdup(rest));
	line = ft_substr(rest, 0, new_index + 1);
	if (!line)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	return (line);
}

char	*update_rest(char *rest)
{
	int		new_index;
	char	*new_rest;

	new_index = find_newline(rest);
	if (new_index == -1)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	new_rest = ft_strdup(rest + new_index + 1);
	if (!new_rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = read_line(fd, rest);
	if (!rest || *rest == '\0')
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = getting_line(rest);
	rest = update_rest(rest);
	return (line);
}
