/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:16 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/14 18:04:29 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_bools(char c, bool *player, bool *exit, bool *collectibles)
{
	if ((!ft_is_charset(c, "01PEC")) || (c == 'P' && *player) || (c == 'E'
			&& *exit))
		return (0);
	if (c == 'P')
		*player = 1;
	if (c == 'E')
		*exit = 1;
	if (c == 'C')
		*collectibles = 1;
	return (1);
}

int	ft_check_map_chars(char **map)
{
	int		i;
	int		j;
	bool	player;
	bool	exit;
	bool	collectibles;

	player = false;
	exit = false;
	collectibles = false;
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (!ft_bools(map[j][i], &player, &exit, &collectibles))
				return (0);
	}
	if (!collectibles || !player || !exit)
		return (0);
	return (1);
}

int	ft_check_map_shape(char **map)
{
	t_point	map_size;

	map_size.x = ft_strlen(map[0]);
	map_size.y = 0;
	while (map[map_size.y])
	{
		if ((int)ft_strlen(map[map_size.y]) != map_size.x)
			return (0);
		map_size.y++;
	}
	return (1);
}

int	ft_check_walls(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (map[j][++i])
		if (map[j][i] != '1')
			return (0);
	while (map[++j])
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			return (0);
	j--;
	i = -1;
	while (map[j][++i])
		if (map[j][i] != '1')
			return (0);
	return (1);
}

void	ft_check_map(char **map)
{
	if (!map || !*map)
		ft_exit_error("Error\n\nEmpty map.", map);
	if (!ft_check_map_chars(map))
		ft_exit_error("Error\nMap must only contain 0/1/P/E/C\n\
0: empty tile\n1: wall\nP: starting position (unique)\nE: exit (unique)\nC:\
 collectibles (1 minimum)", map);
	if (!ft_check_map_shape(map))
		ft_exit_error("Map must be a rectangle.", map);
	if (!ft_check_walls(map))
		ft_exit_error("Error\n\nMap must be surrounded by walls.", map);
	if (!ft_is_explorable(map))
		ft_exit_error("Error\n\nExit and Collectibles must be reachable by the\
 player.", map);
}
