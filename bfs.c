/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 08:02:34 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/05 19:56:20 by fvaliyak         ###   ########.fr       */
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

void	check_path(t_map *map, int i, int j, t_stack **visited )
{
	char	**arr;

	arr = map->map;
	*visited = create_node(visited, i, j);
	if (arr[i][j] == 'E')
	{
		map->valid_path = 1;
		return ;
	}
	if (arr[i][j] == 'C')
		map->reachable_c++;
	if (arr[i + 1][j] != '1' && (is_visited(*visited, i + 1, j) == 0))
		check_path(map, i + 1, j, visited);
	if (arr[i - 1][j] != '1' && (is_visited(*visited, i - 1, j) == 0))
		check_path(map, i - 1, j, visited);
	if (arr[i][j + 1] != '1' && (is_visited(*visited, i, j + 1) == 0))
		check_path(map, i, j + 1, visited);
	if (arr[i][j - 1] != '1' && (is_visited(*visited, i, j - 1) == 0))
		check_path(map, i, j - 1, visited);
}

void	bfs(t_map *map)
{
	int		i;
	int		j;
	t_stack	*visited;

	visited = map->visited_node;
	i = 1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				break ;
			j++;
		}
		if (map->map[i][j] == 'P')
		{
			visited = create_node(&visited, i, j);
			break ;
		}
		i++;
	}
	check_path(map, i, j, &visited);
}
