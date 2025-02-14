/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:49:08 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/18 12:32:02 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sublen(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return (0);
	if (len > ft_strlen(s + start))
		return (ft_strlen(s + start));
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_sublen(s, start, len) + 1));
	if (!str)
		return (NULL);
	if ((size_t)start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = 0;
	return (str);
}
