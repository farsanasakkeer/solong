/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:48:27 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/04/03 13:01:57 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;
void	init_map(t_map *map)
{
	map->img_width = 48;
	map->img_height = 48;
	map->wall = "./images/wall.xpm";
	map->path = "./images/free_tile.xpm";
	map->exit = "./images/door.xpm";
	map->entry = "./images/door.xpm";
	map->coin = "./images/coin.xpm";
	map->player = "./images/knor.xpm";
}
void	 ft_create_map(t_map *map,char **arr,int row)
{
	map->map_width = is_closed(arr, row-1);
	map->map_width = map->map_width * map->img_width;
	map->map_height = row * map->img_height ;
	check_C_E_P(arr,(int)0,(int)0,(int)0);
	bfs(arr);
	printf("--%d * %d --\n",map->map_height,map->map_width);
	
}

int main()
{
	int		fd;
	char	**arr;
	int		row;
	t_map	map;

	row = 0;
	fd = open ("map.ber",O_RDONLY);
	while(1)
	{
		if (get_next_line(fd) == NULL)
			break;
		row++;
	}
	close(fd);
	map.filename = "map.ber";
	fd = open (map.filename, O_RDONLY);
	arr = creat_array(row,fd);
	close(fd);
	
	printf("-----\n");
	
	init_map(&map);
	ft_create_map(&map, arr, row);
	map.mlx = mlx_init();
	printf("---%d * %d-=-\n",map.map_height,map.map_width);
	map.win = mlx_new_window(map.mlx, map.map_width, \
		map.map_height, "Welcome !");
	mlx_loop(map.mlx);
	
}
