/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:44:32 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/13 14:43:09 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_map_size(char **map)
{
	t_point	map_size;
	int		height;

	height = 0;
	while (map[height])
		height++;
	map_size.x = ft_strlen(map[0]);
	map_size.y = height;
	return (map_size);
}

void	ft_coordinates(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}
