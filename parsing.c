/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:46:53 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/12 15:56:39 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creat_array(int row, int fd, t_map *map)
{
	int		index;
	char	*s;
	char	*str;
	size_t	col;

	index = 0;
	map->map = malloc ((row + 1) * sizeof(char *));
	map->map[row] = NULL;
	while (row--)
	{
		s = get_next_line(fd);
		if (!row)
			if (ft_strchr(s, '\n'))
				exit_error(s, map);
		str = ft_strtrim(s, "\n");
		free(s);
		if (index == 0)
			col = ft_strlen(str);
		if (col != ft_strlen(str))
			exit_error(str, map);
		map->map[index++] = str;
		map->row = index;
	}
}

int	is_closed(char **arr, int row, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= row)
	{
		j = 0;
		while (arr[i][j])
		{
			if (i == 0 || i == row || j == 0 || arr[i][j + 1] == '\0')
			{
				if (arr[i][j] != '1')
				{
					ft_printf("Not Colsed\n");
					exit_error(NULL, map);
				}
			}
			j++;
		}
		i++;
	}
	if (row + 1 == j)
		exit_error(NULL, map);
	return (j);
}

void	check_c_e_p(t_map *map, int C, int P, int E)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				C++;
			else if (map->map[i][j] == 'E')
				E++;
			else if (map->map[i][j] == 'P')
				P++;
			else if (map->map[i][j] == '1' || map->map[i][j] == '0')
				continue ;
			else
				exit_error(NULL, map);
		}
		i++;
	}
	map->c_count = C;
	if (C == 0 || E != 1 || P != 1)
		exit_error(NULL, map);
}
