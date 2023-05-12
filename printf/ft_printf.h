/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:13:04 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/12/04 19:16:41 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	format_arg(va_list arg, const char data);
int	print_hex(unsigned int n, char format);
int	print_nbr(int nbr, char format);
int	print_unsignesint(unsigned int n);
int	printstr(char *str);
int	printchar(int c);
int	print_pointer(unsigned long n, int a);
#endif