/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:31:56 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/21 15:27:58 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex_len(unsigned int n)
{
	char	*base;
	int		i;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_putnbr_hex_len(n / 16);
	i = n % 16;
	write(1, &base[i], 1);
	len++;
	return (len);
}

int	ft_putnbr_hex_len_up(unsigned int n)
{
	char	*base;
	int		i;
	int		len;

	base = "0123456789ABCDEF";
	len = 0;
	if (n >= 16)
		len += ft_putnbr_hex_len_up(n / 16);
	i = n % 16;
	write(1, &base[i], 1);
	len++;
	return (len);
}
