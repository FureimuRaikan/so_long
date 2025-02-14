/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:15:09 by yguinio           #+#    #+#             */
/*   Updated: 2024/11/18 08:49:21 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_trimlen(size_t start, size_t end)
{
	if (end == 0)
		return (0);
	return (end + 1 - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trim;

	start = 0;
	while (ft_isset(s1[start], set) && start < ft_strlen(s1))
		start++;
	if (!ft_strlen(s1))
		end = 0;
	else
		end = ft_strlen(s1) - 1;
	while (ft_isset(s1[end], set) && end >= start)
		end--;
	trim = (char *)malloc(sizeof(char) * (ft_trimlen(start, end) + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while (start + i <= end && end)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = 0;
	return (trim);
}
