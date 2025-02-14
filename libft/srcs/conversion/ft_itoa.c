/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:15:42 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/21 11:02:19 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnegative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static size_t	ft_nblen(int n)
{
	size_t		i;
	long int	nb;

	i = 1;
	nb = n;
	if (ft_isnegative(n))
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t			i;
	long int		nb;
	char			*str;
	size_t const	nblen = ft_nblen(n);

	i = 0;
	nb = n;
	str = (char *)malloc(sizeof(char) * (nblen + 1));
	if (!str)
		return (NULL);
	if (ft_isnegative(n))
		nb *= -1;
	while (nb > 9)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	str[i++] = nb + 48;
	if (ft_isnegative(n))
		str[i++] = '-';
	str[i] = 0;
	return (ft_reverse(str));
}
