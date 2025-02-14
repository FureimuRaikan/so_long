/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:41:32 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/21 15:39:08 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sort(char c, va_list arg)
{
	if (c == 's')
		return (ft_putstr_len(va_arg(arg, char *)));
	if (c == 'c')
		return (ft_putchar_len(va_arg(arg, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_len(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putunbr_len(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hex_len(va_arg(arg, unsigned int)));
	if (c == 'X')
		return (ft_putnbr_hex_len_up(va_arg(arg, unsigned int)));
	if (c == 'p')
		return (ft_putptr_len(va_arg(arg, void *)));
	if (c == '%')
		return (ft_putchar_len('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	if (!str)
		return (-1);
	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_sort(str[i + 1], args);
			i++;
		}
		else
			len += ft_putchar_len(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
