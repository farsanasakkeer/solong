/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imaging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:10:14 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/05 17:57:28 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map	*map, int a, int b)
{
	if (map->map[map->pi + a][map->pj + b] == 'E' && map->c_count == 0)
	{
		map->map[map->pi][map->pj] = '0';
		map->move_count++;
		write(1, "YOU WON !!!\n", 12);
		exit_error1(map);
	}
	else if (map->map[map->pi + a][map->pj + b] == 'E' && map->c_count != 0)
		write(1, "coins remaining\n", 16);
	else if (map->map[map->pi + a][map->pj + b] == '1')
		write(1, "can't move\n", 11);
	else if (map->map[map->pi + a][map->pj + b] == '0'
		|| map->map[map->pi + a][map->pj + b] == 'C')
	{
		if (map->map[map->pi + a][map->pj + b] == 'C')
			map->c_count--;
		map->map[map->pi + a][map->pj + b] = 'P';
		map->map[map->pi][map->pj] = '0';
		map->move_count++;
		ft_printf("no of moves : %d\n", map->move_count);
		map->pi += a;
		map->pj += b;
	}
}

int	game_hook(int keycode, t_map *map)
{
	if (keycode == 13 || keycode == 126)
		move_player(map, -1, 0);
	else if (keycode == 1 || keycode == 125)
		move_player(map, 1, 0);
	else if (keycode == 0 || keycode == 123)
		move_player(map, 0, -1);
	else if (keycode == 2 || keycode == 124)
		move_player(map, 0, 1);
	if (keycode == 53)
		exit_error1(map);
	map->py = 0;
	img_put(map, -1, -1);
	return (0);
}
