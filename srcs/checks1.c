/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:40:03 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/13 15:22:58 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_is_ber(char *file)
{
	char	*rev;
	int		i;

	i = 0;
	rev = ft_strdup(file);
	ft_reverse(rev);
	if (ft_strncmp(rev, "reb.", 4))
		return (free(rev), 0);
	return (free(rev), 1);
}

static t_point	ft_find_position(char c, char **map)
{
	int		i;
	int		j;
	t_point	coords;

	coords.x = 0;
	coords.y = 0;
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == c)
			{
				coords.x = i;
				coords.y = j;
				return (coords);
			}
		}
	}
	coords.x = -1;
	coords.y = -1;
	return (coords);
}

static void	ft_flood_fill(char **tab, t_point size, t_point begin)
{
	t_point	p;

	if (tab[begin.y][begin.x] == 'A')
		return ;
	tab[begin.y][begin.x] = 'A';
	if (begin.y > 0 && tab[begin.y - 1][begin.x] != '1')
	{
		ft_coordinates(&p, begin.x, begin.y - 1);
		ft_flood_fill(tab, size, p);
	}
	if ((begin.y < (size.y - 1)) && tab[begin.y + 1][begin.x] != '1')
	{
		ft_coordinates(&p, begin.x, begin.y + 1);
		ft_flood_fill(tab, size, p);
	}
	if ((begin.x < (size.x - 1)) && tab[begin.y][begin.x + 1] != '1')
	{
		ft_coordinates(&p, begin.x + 1, begin.y);
		ft_flood_fill(tab, size, p);
	}
	if (begin.x > 0 && tab[begin.y][begin.x - 1] != '1')
	{
		ft_coordinates(&p, begin.x - 1, begin.y);
		ft_flood_fill(tab, size, p);
	}
}

int	ft_is_explorable(char **map)
{
	t_point	player;
	t_point	map_size;
	char	**temp_map;
	int		i;
	int		j;

	temp_map = ft_array_str_dup(map);
	if (!temp_map)
		return (0);
	player = ft_find_position('P', temp_map);
	map_size = ft_map_size(temp_map);
	ft_flood_fill(temp_map, map_size, player);
	j = -1;
	while (temp_map[++j])
	{
		i = -1;
		while (temp_map[j][++i])
			if (ft_is_charset(temp_map[j][i], "PEC"))
				return (ft_free_split(temp_map), 0);
	}
	return (ft_free_split(temp_map), 1);
}
