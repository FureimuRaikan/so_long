/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_dup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:45:34 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/13 15:08:23 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_str_dup(char **array)
{
	int		i;
	char	**dup;

	if (!array || !*array)
		return (NULL);
	i = 0;
	while (array[i])
		i++;
	dup = (char **)ft_calloc(sizeof(char *), i + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (array[++i])
		dup[i] = ft_strdup(array[i]);
	dup[i] = NULL;
	return (dup);
}
