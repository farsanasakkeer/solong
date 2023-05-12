/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:18:23 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/04/13 16:51:58 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_unsignesint(unsigned int n)
{
	int		i;

	i = 0;
	if (n <= 9)
	{
		i += printchar("0123456789"[n]);
	}
	else
	{
		i += print_unsignesint(n / 10);
		i += printchar("0123456789"[n % 10]);
	}
	return (i);
}

int	print_nbr(int nbr, char format)
{
	unsigned int	n;
	int				i;

	i = 0;
	if (nbr < 0)
	{
		i += write (1, "-", 1);
		n = (unsigned int)(nbr * -1);
	}
	else
		n = (unsigned int)nbr;
	if (n <= 9)
	{
		i += printchar("0123456789"[n]);
	}
	else
	{
		i += print_nbr(n / 10, format);
		i += print_nbr(n % 10, format);
	}
	return (i);
}

int	print_hex(unsigned int n, char format)
{
	int		i;

	i = 0;
	if (n <= 15 && format == 'x')
	{
		i += printchar("0123456789abcdef"[n]);
	}
	else if (n <= 15 && format == 'X')
	{
		i += printchar("0123456789ABCDEF"[n]);
	}
	else if (format == 'x')
	{
		i += print_hex(n / 16, format);
		i += printchar("0123456789abcdef"[n % 16]);
	}
	else if (format == 'X')
	{
		i += print_hex(n / 16, format);
		i += printchar("0123456789ABCDEF"[n % 16]);
	}
	return (i);
}

int	print_pointer(unsigned long n, int a)
{
	int		i;

	i = 0;
	if (a == 0)
	{
	i += write(1, "0x", 2);
	}
	if (n <= 15)
	{
		i += printchar("0123456789abcdef"[n]);
	}
	else
	{
		i += print_pointer((n / 16), 1);
		i += printchar("0123456789abcdef"[n % 16]);
	}
	return (i);
}
