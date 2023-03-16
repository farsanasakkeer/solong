/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:00:30 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/16 18:05:52 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft1_strlen(char *s);
char	*ft1_strchr(char *s, int c);
char	*ft1_strjoin(char *left_str, char *str);
char	*read_file(int fd, char *buffer);
char	*get_line(char *buffer);
char	*update_buffer(char *buffer);
char	*get_next_line(int fd);

#endif