/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:05:41 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/21 15:27:58 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_len(void *ptr)
{
	char const	*base = "0123456789abcdef";
	char		*str;
	int			len;

	if (!ptr)
		return (ft_putstr_len("(nil)"));
	len = ft_putstr_len("0x");
	str = ft_ulitoa_base((unsigned long int )ptr, base);
	len += ft_putstr_len(str);
	free(str);
	return (len);
}
