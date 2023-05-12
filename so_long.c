/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:48:27 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/05 21:37:30 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initial_checking(int argn, char **argv)
{
	int		fd;
	int		row;
	int		len;

	row = 0;
	if (argn != 2)
		exit(1);
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e' || \
			argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		exit(1);
	fd = open (argv[1], O_RDONLY);
	while (1)
	{
		if (get_next_line(fd) == NULL)
			break ;
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
	mlx_hook(map.win, 17, 1L << 0, exit_error1, &map);
	mlx_loop(map.mlx);
}
