/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:32:45 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/21 15:33:12 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulitoa_base(unsigned long int n, const char *base)
{
	size_t			i;
	char			*str;
	size_t const	nblen = ft_unblen_base(n, base);
	size_t const	baselen = ft_strlen(base);

	i = 0;
	str = (char *)malloc(sizeof(char) * (nblen + 1));
	if (!str)
		return (NULL);
	while (n > ft_unblen_base(n, base))
	{
		str[i] = base[(n % baselen)];
		n /= baselen;
		i++;
	}
	if (n)
		str[i++] = base[(n % baselen)];
	str[i] = 0;
	return (ft_reverse(str));
}
