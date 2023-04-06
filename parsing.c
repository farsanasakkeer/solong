/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:46:53 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/04/03 09:53:13 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(char *str, char **arr)
{
	int	i;

	write (1, "Error\n", 6);
	if (str)
		free(str);
	if (arr)
	{
		i = 0;
		while (arr[i])
			free (arr[i++]);
		free (arr);
	}
	exit(1);
}

int	is_closed(char **arr, int row)
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
					exit_error(NULL, arr);
			}
			j++;
		}
		i++;
	}
	if (row + 1 == j)
		exit_error(NULL, arr);
	return (j);
}

void	check_C_E_P(char **arr, int C, int P, int E)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] == 'C')
				C++;
			else if (arr[i][j] == 'E')
				E++;
			else if (arr[i][j] == 'P')
				P++;
			else if (arr[i][j] == '1' || arr[i][j] == '0')
				continue ;
			else
				exit_error(NULL, arr);
		}
		i++;
	}
	if (C == 0 || E != 1 || P != 1)
		exit_error(NULL, arr);
}

char	**creat_array(int row, int fd)//free arr at exit
{
	int		index;
	char	**arr;
	char	*s;
	char	*str;
	size_t	col;

	index = 0;
	arr = malloc ((row + 1) * sizeof(char *));
	arr[row] = NULL;
	while (row--)
	{
		s = get_next_line(fd);
		if (!row)
			if (ft_strchr(s, '\n'))
				exit_error(s, NULL);
		str = ft_strtrim(s, "\n");
		free(s);
		if (index == 0)
			col = ft_strlen(str);
		if (col != ft_strlen(str))
			exit_error(str, NULL);
		arr[index++] = str;
	}
	return (arr);
}

/*
// int i=0;
	// //int j=0;
	// while(arr[i])
	// {
	// 	// while(arr[i][j])
	// 	// {
	// 		printf("%s\n",arr[i++]);
	// 	// 	printf(" (%d %d)\n",i,j);
	// 	// }
	// 	// i++;
	// 	// j=0;
		
	// }
	// printf("\n%c\n",arr[3][1]);
	*/