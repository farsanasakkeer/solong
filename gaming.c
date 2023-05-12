/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:24:44 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/05 21:29:08 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->pi = i;
				map->pj = j;
				return ;
			}
			j++;
		}
	}
}

void	init_img(t_map *map)
{
	map->wall = mlx_xpm_file_to_image(map->mlx, \
					map->wall, &map->img_width, &map->img_height);
	map->path = mlx_xpm_file_to_image(map->mlx, \
					map->path, &map->img_width, &map->img_height);
	map->exit = mlx_xpm_file_to_image(map->mlx, \
					map->exit, &map->img_width, &map->img_height);
	map->coin = mlx_xpm_file_to_image(map->mlx, \
					map->coin, &map->img_width, &map->img_height);
	map->player = mlx_xpm_file_to_image(map->mlx, \
					map->player, &map->img_width, &map->img_height);
	if (map->path == NULL || map->coin == NULL || \
			map->wall == NULL || map->exit == NULL || map->player == NULL)
	{
		write(1, "Image does not exist!\n", 22);
		exit_error1(map);
	}
}

void	img_put(t_map *map, int i, int j)
{
	while (map->map[++i])
	{
		j = -1;
		map->px = 0;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, \
								map->win, map->wall, map->px, map->py);
			else if (map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, \
								map->win, map->path, map->px, map->py);
			else if (map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, \
								map->win, map->exit, map->px, map->py);
			else if (map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, \
								map->win, map->player, map->px, map->py);
			else if (map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, \
								map->win, map->coin, map->px, map->py);
			map->px += 48;
		}
		map->py += 48;
	}
}

void	init_map(t_map *map)
{
	map->img_width = 48;
	map->img_height = 48;
	map->wall = "./images/wall.xpm";
	map->path = "./images/path.xpm";
	map->exit = "./images/exit.xpm";
	map->coin = "./images/coin.xpm";
	map->player = "./images/player.xpm";
	map->move_count = 0;
	map->py = 0;
	map->reachable_c = 0;
	map->valid_path = 0;
	map->visited_node = NULL;
}

void	ft_create_map(t_map *map, char **arr, int row)
{
	map->column = is_closed(arr, row - 1, map);
	map->row = row;
	map->map_width = map->column * map->img_width;
	map->map_height = row * map->img_height ;
	map->map = arr;
	check_c_e_p(map, (int)0, (int)0, (int)0);
	bfs(map);
	if (map->valid_path != 1 || map->c_count != map-> reachable_c)
	{
		ft_printf("Not reachable\n");
		exit_error(NULL, map);
	}
	player_position(map);
}
