/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 08:02:34 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/04/03 10:16:25 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_visited(t_stack *stack, int x, int y)
{
	while ((stack)->next != NULL)
	{
		if ((stack)->i == x && (stack)->j == y)
			return (1);
		(stack) = (stack)->next;
	}
	return (0);
}

t_stack	*create_node(t_stack **top, int i, int j)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	newnode->i = i;
	newnode->j = j;
	if (top == NULL)
	{
		top = &newnode;
		(*top)->next = NULL;
	}
	else
	{
		newnode->next = *top;
		top = &newnode;
	}
	return (*top);
}

void	check_path(char **arr, int i, int j, t_stack **visited )
{
	*visited = create_node(visited, i, j);
	if (arr[i][j] == 'E')
		return ;
	if (arr[i + 1][j] != '1' && (is_visited(*visited, i + 1, j) == 0))
		check_path(arr, i + 1, j, visited);
	if (arr[i - 1][j] != '1' && (is_visited(*visited, i - 1, j) == 0))
		check_path(arr, i - 1, j, visited);
	if (arr[i][j + 1] != '1' && (is_visited(*visited, i, j + 1) == 0))
		check_path(arr, i, j + 1, visited);
	if (arr[i][j - 1] != '1' && (is_visited(*visited, i, j - 1) == 0))
		check_path(arr, i, j - 1, visited);
}

void	bfs(char **arr)
{
	int		i;
	int		j;
	t_stack	*visited;

	visited = NULL;
	i = 1;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
				break ;
			j++;
		}
		if (arr[i][j] == 'P')
		{
			visited = create_node(&visited, i, j);
			break ;
		}
		i++;
	}
	check_path(arr, i, j, &visited);
}
