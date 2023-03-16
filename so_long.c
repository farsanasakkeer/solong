/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:48:27 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/16 21:54:30 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline/get_next_line.h"
#include "libft/libft.h"
#include<stdio.h>
#include<fcntl.h>

void	exit_error(char *str)
{
	write (1,"Error\n",6);
	if (str)
		free(str);
	exit(1);
	
}
char	**creat_array(int row,int fd)
{
	int		index;
	char	**arr;
	char	*s;
	char	*str;
	size_t	col;
	//int		fd;
	
	index = 0;
	//fd = open ("map.ber",O_RDONLY);
	arr = malloc((row + 1)*sizeof(char *));
	arr[row] = NULL;
	while (row--)
	{
		s = get_next_line(fd);
		str = ft_strtrim(s, "\n");
		free(s);
		if (index == 0)
			col = ft_strlen(str);
		if (col != ft_strlen(str))
			exit_error(str);
		arr[index++] = str;
		free(str);
	}
	return(arr);
}
int main()
{
	int		fd;
	char	**arr;
	int		row;

	row = 0;
	fd = open ("map.ber",O_RDONLY);
	while(1)
	{
		if (get_next_line(fd) == NULL)
			break;
		row++;
	}
	close(fd);
	fd = open ("map.ber",O_RDONLY);
	printf("%d\n",row);
	arr = creat_array(row,fd);
	close(fd);
	
	// int i=0;
	// int j=0;
	// while(i<=4)
	// {
	// 	while(j<=13)
	// 	{
	// 		printf("%c",arr[i][j++]);
	// 		printf(" (%d %d)\n",i,j);
	// 	}
	// 	i++;
	// 	j=0;
		
	// }
}

// 		while (i<13)
// 			printf("%c",arr[index -1 ][i++]);
// 		printf("\n");

// int i=0;
	// int j=0;
	// while(i<=4)
	// {
	// 	while(j<=12)
	// 	{
	// 		printf("%c",arr[i][j++]);
	// 	}
	// 	i++;
	// 	j=0;
	// 	printf("\n");
	// }