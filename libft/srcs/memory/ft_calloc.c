/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:18:10 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/26 10:51:46 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;

	if (!nmemb || !size)
		return (NULL);
	if (size && ((nmemb * size) / nmemb != size))
		return (NULL);
	buff = (void *)malloc(size * nmemb);
	if (!buff)
		return (NULL);
	ft_bzero(buff, (nmemb * size));
	return (buff);
}
