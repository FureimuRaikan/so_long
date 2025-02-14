/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:45:18 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/16 17:36:04 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*j;

	i = 0;
	j = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			j = (char *)s + i;
		i++;
	}
	if (s[i] == (unsigned char)c)
		j = (char *)s + i;
	return (j);
}
