/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:12:45 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/24 09:57:55 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_len(int n)
{
	int		i;
	char	*nbr;

	nbr = ft_itoa(n);
	i = ft_putstr_len(nbr);
	free (nbr);
	return (i);
}

int	ft_putunbr_len(unsigned int n)
{
	int		i;
	char	*nbr;

	nbr = ft_uitoa(n);
	i = ft_putstr_len(nbr);
	free (nbr);
	return (i);
}
