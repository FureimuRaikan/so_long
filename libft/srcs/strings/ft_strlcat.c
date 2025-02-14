/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:13:31 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/16 11:00:32 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t			i;
	size_t const	dst_len = ft_strlen(dst);
	size_t const	src_len = ft_strlen(src);

	i = 0;
	if (!siz)
		return (src_len);
	if (siz < dst_len)
		return (src_len + siz);
	while (src[i] && (dst_len + i) < siz - 1)
	{
			dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = 0;
	return (src_len + dst_len);
}
