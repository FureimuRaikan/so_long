/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:18:10 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/26 14:57:28 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;

	if (size && ((nmemb * size) / nmemb != size))
		return (NULL);
	buff = (void *)malloc(size * nmemb);
	if (!buff)
		return (NULL);
	ft_bzero(buff, (nmemb * size));
	return (buff);
}
