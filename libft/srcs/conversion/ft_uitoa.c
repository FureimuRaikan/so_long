/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:42 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/21 15:32:34 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	size_t			i;
	char			*str;
	size_t const	nblen = ft_unblen_base(n, "0123456789");

	i = 0;
	str = (char *)malloc(sizeof(char) * (nblen + 1));
	if (!str)
		return (NULL);
	while (n > 9)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	str[i++] = n + 48;
	str[i] = 0;
	return (ft_reverse(str));
}
