/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr_base_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:57 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/21 15:34:19 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_unblen_base(unsigned long int n, const char *base)
{
	size_t			i;
	const size_t	baselen = ft_strlen(base);

	i = 1;
	while (n > baselen - 1)
	{
		n /= (baselen);
		i++;
	}
	return (i);
}
