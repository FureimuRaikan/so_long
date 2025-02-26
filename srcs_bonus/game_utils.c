/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:44:32 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/24 15:37:00 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Returns the sizwe of the map inside a t_point
void	ft_map_size(t_solong *solong)
{
	solong->map_size.x = (int)ft_strlen(solong->map[0]);
	solong->map_size.y = 0;
	while (solong->map[solong->map_size.y])
		solong->map_size.y++;
}

//Sets coordinates to a given t_point*
void	ft_set_coordinates(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

//Returns a t_point containing the x and y given coordinates
t_point	ft_create_coordinates(int x, int y)
{
	t_point	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

//Finds the coordinates of the first occurrence of given char inside the map
//(-1 if not found)
t_point	ft_find_coordinates(char c, char **map)
{
	int		x;
	int		y;
	t_point	coords;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == c)
			{
				coords.x = x;
				coords.y = y;
				return (coords);
			}
		}
	}
	coords.x = -1;
	coords.y = -1;
	return (coords);
}

//Checks if there's still collectibles inside the map
bool	ft_is_collectibles(char **map)
{
	int	x;
	int	y;
	int	is_collectible;

	is_collectible = false;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'C')
				is_collectible = true;
	}
	return (is_collectible);
}
