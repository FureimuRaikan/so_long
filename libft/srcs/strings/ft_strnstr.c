/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:41:49 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/16 10:42:21 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (i < len && big[i])
	{
		if (little[0] == big[i])
		{
			temp = i;
			j = 0;
			while (little[j] == big[temp] && little[j] && (temp < len))
			{
				temp++;
				j++;
			}
			if (!little[j])
				return ((char *)(big + temp - j));
		}
		i++;
	}
	return (NULL);
}
