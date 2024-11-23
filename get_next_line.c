/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-majd <ael-majd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:10:18 by ael-majd          #+#    #+#             */
/*   Updated: 2024/11/23 16:11:09 by ael-majd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;
	int		len;

	len = ft_strlen(s) + 1;
	d = malloc(sizeof(char) * len);
	if (!d)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int find_newline(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while(s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
char *full_read(int fd, char *rest)
{
	char *full;
	int byte_read;
	char buffer[BUFFER_SIZE + 1];
	
	while((byte_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[byte_read] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (find_newline(rest) >= 0)
			break;
	}
	return (rest);
}
char *get_line(char *rest)
{
	char *line;
	int new_index;

	new_index = find_newline(rest);
	if (new_index < 0)
		return (ft_strdup(rest));
	line = ft_substr(rest, 0, new_index + 1);
	return (line);
}

char *update_rest(char *rest)
{
	int new_index;
	char *new_rest;

	new_index = find_newline(rest);
	if (new_index == -1)
	{
		free(rest);
		return (NULL);
	}
	new_rest = ft_strdup(rest + new_index + 1);
	free(rest);
	return (new_rest);
}
char *get_next_line(int fd)
{
	static char *rest;
	char *line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 0)
		return (NULL);
	rest = full_read(fd,rest);
	if (!rest || *rest == '\0')
    {
        free(rest);
        rest = NULL;
        return (NULL);
    }
	line = get_line(rest);
	rest = update_rest(rest);
	return (line);
}
// void le()
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	int fd = open("file", O_RDONLY | O_CREAT);
// 	char *line;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	printf("\n");
// 	int fd1 = open("file1", O_RDONLY | O_CREAT);
// 	char *line1;
// 	while ((line1 = get_next_line(fd1)))
// 	{
// 		printf("%s", line1);
// 		free(line1);
// 	}
// 	close(fd);
// 	atexit(le);
// }