/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:55:43 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/16 18:07:38 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *buffer)
{
	char	*str;
	int		rd;

	str = malloc(((unsigned int)BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	rd = 1;
	while (!(ft1_strchr(buffer, '\n')) && rd != 0)
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			return (NULL);
		}
		str[rd] = '\0';
		buffer = ft1_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && (buffer[i] != '\n'))
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	k = ++i;
	i = ft1_strlen(buffer);
	str = (char *)malloc((i - k + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[k])
		str[j++] = buffer[k++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
