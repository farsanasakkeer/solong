/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:12:31 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/12 20:30:56 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "getnextline/get_next_line.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct s_stack
{
	int				i;
	int				j;
	struct s_stack	*next;
}					t_stack;

typedef struct s_map
{
	void	*mlx;
	char	*filename;
	int		column;
	int		row;
	int		map_width;
	int		map_height;
	void	*win;
	int		img_width;
	int		img_height;
	char	*wall;
	char	*path;
	char	*exit;
	char	*entry;
	char	*coin;
	char	*player;
	char	**map;
	int		pi;
	int		pj;
	int		px;
	int		py;
	int		c_count;
	int		reachable_c;
	int		move_count;
	int		valid_path;
	t_stack	*visited_node;
}					t_map;
void	exit_error(char *str, t_map *map);
void	image_free(t_map *map);
int		exit_error1(t_map *map);
int		finish(t_map *map);
void	free_stack(t_stack **stack);
int		initial_checking(int argn, char **argv);
int		is_closed(char **arr, int row, t_map *map);
void	check_c_e_p(t_map *map, int C, int P, int E);
void	creat_array(int row, int fd, t_map *map);
void	bfs(t_map *map);
void	arg_check(int argn, char **a);
void	check_path(t_map *map, int i, int j, t_stack **visited );

t_stack	*create_node(t_stack **top, int i, int j);
int		is_visited(t_stack *stack, int x, int y);

void	init_img(t_map *map);
void	img_put(t_map *map, int i, int j);
void	init_map(t_map *map);
void	ft_create_map(t_map *map, char **arr, int row);
void	move_player(t_map	*map, int a, int b);
int		game_hook(int keycode, t_map *map);

#endif
