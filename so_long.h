/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:12:31 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/04/03 12:34:15 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "getnextline/get_next_line.h"
# include "libft/libft.h"
# include<stdio.h>
# include<fcntl.h>
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


}					t_map;
void	exit_error(char *str, char **arr);
int		is_closed(char **arr, int row);
void	check_C_E_P(char **arr, int C, int P, int E);
char	**creat_array(int row, int fd);
void	bfs(char **arr);
void	check_path(char **arr, int i, int j, t_stack **visited );
t_stack	*create_node(t_stack **top, int i, int j);
int	is_visited(t_stack *stack,int x,int y);

#endif