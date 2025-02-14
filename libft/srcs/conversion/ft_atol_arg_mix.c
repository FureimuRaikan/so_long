/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_arg_mix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:58:37 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/21 23:00:42 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_whitespace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	ft_check_overflow(long long number, int is_negative)
{
	if (is_negative == 1 && number > LONG_MAX - 1)
		return (0);
	else if (is_negative == -1 && number > LONG_MAX)
		return (0);
	else
		return (1);
}

long	ft_atol_arg_mix(const char *nptr, int *next_nbr)
{
	size_t	i;
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	i = *next_nbr;
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
		i++;
	}
	if (nptr[i])
		*next_nbr = i;
	if (!nptr[i])
		*next_nbr = 0;
	return (ft_check_overflow(nbr, sign) * nbr * sign);
}
