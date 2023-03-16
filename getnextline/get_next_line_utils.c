/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:58:19 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/16 18:08:23 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft1_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft1_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft1_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft1_strjoin(char *left_str, char *str)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !str)
		return (NULL);
	join = malloc(sizeof(char) * ((ft1_strlen(left_str) + ft1_strlen(str)) + 1));
	if (join == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			join[i] = left_str[i];
	while (str[j] != '\0')
		join[i++] = str[j++];
	join[ft1_strlen(left_str) + ft1_strlen(str)] = '\0';
	free(left_str);
	return (join);
}
