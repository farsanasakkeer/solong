/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:06:03 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/12 15:59:05 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	image_free(t_map *map)
{
	if (map->wall)
		mlx_destroy_image(map->mlx, map->wall);
	if (map->path)
		mlx_destroy_image(map->mlx, map->path);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->coin)
		mlx_destroy_image(map->mlx, map->coin);
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
	return ;
}

void	exit_error(char *str, t_map *map)
{
	int	i;

	if (str)
		free(str);
	if (map->map)
	{
		i = 0;
		while (map->row--)
		{
			free (map->map[i++]);
		}
		free (map->map);
	}
	free_stack(&map->visited_node);
	ft_printf("Error\n");
	exit(1);
}

int	exit_error1(t_map *map)
{
	int	i;

	if (map->map)
	{
		i = 0;
		while (map->map[i])
			free (map->map[i++]);
		free (map->map);
	}
	image_free(map);
	free_stack(&map->visited_node);
	ft_printf("Bye\n");
	exit(1);
}
