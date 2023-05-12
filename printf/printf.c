/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:42:24 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/05/05 16:46:38 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	format_arg(va_list arg, const char data)
{
	int	p_len;

	p_len = 0;
	if (data == 'c')
		return (printchar(va_arg(arg, int)));
	else if (data == 's')
		return (printstr(va_arg(arg, char *)));
	else if (data == 'd' || data == 'i')
		return (print_nbr(va_arg(arg, int), data));
	else if (data == 'u')
		return (print_unsignesint(va_arg(arg, unsigned int)));
	else if (data == 'x' || data == 'X')
		return (print_hex(va_arg(arg, unsigned int), data));
	else if (data == 'p')
		return (print_pointer(va_arg(arg, unsigned long), 0));
	else if (data == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (p_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		p_len;
	va_list	arg;

	i = 0;
	p_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			p_len += format_arg(arg, str[i + 1]);
			i++;
		}
		else
			p_len += printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (p_len);
}
