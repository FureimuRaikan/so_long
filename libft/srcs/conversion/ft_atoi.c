/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:58:37 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/21 22:57:08 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	is_overflowing(long number, int is_negative)
{
	if (is_negative == 1 && number > INT_MAX - 1)
		return (1);
	else if (is_negative == -1 && number > INT_MAX)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = (nbr * 10) + nptr[i] - 48;
		if (is_overflowing(nbr, sign))
			return (0);
		i++;
	}
	return (nbr * sign);
}
