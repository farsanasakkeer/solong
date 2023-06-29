/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:48:27 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/12 20:31:33 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	finish(t_map *map)
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
	exit(0);
}

void	arg_check(int argn, char **a)
{
	int		l;

	if (argn != 2)
	{
		ft_printf("Error\nIt should be like: ./so_long map.ber\n");
		exit(1);
	}
	l = ft_strlen(a[1]);
	if (a[1][l - 1] != 'r' || a[1][l - 2] != 'e' || \
				a[1][l - 3] != 'b' || a[1][l - 4] != '.')
	{
		ft_printf("Wrong filename \n");
		exit(1);
	}
}

int	initial_checking(int argn, char **a)
{
	int		fd;
	int		row;
	char	*s;

	row = 0;
	arg_check(argn, a);
	fd = open (a[1], O_RDONLY);
	if (fd <= 2)
	{
		ft_printf("Map file not found!\n");
		close(fd);
		exit (1);
	}
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		free (s);
		row++;
	}
	close(fd);
	return (row);
}

int	main(int argn, char **argv)
{
	int		fd;
	int		row;
	t_map	map;

	row = initial_checking(argn, argv);
	map.filename = argv[1];
	fd = open (map.filename, O_RDONLY);
	creat_array(row, fd, &map);
	close(fd);
	init_map(&map);
	ft_create_map(&map, map.map, row);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.map_width, \
		map.map_height, "Welcome !");
	init_img(&map);
	img_put(&map, -1, -1);
	if (map.px > 1920 || map.py > 1080)
	{
		ft_printf("Window size greater than 1920*1080\n");
		exit_error1(&map);
	}
	mlx_hook(map.win, 2, 1L << 0, game_hook, &map);
	mlx_hook(map.win, 17, 1L << 0, finish, &map);
	mlx_loop(map.mlx);
}
