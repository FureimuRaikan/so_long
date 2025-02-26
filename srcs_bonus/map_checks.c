/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:10:16 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/25 10:27:21 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Checks if the map is a .ber file
int	ft_map_is_ber(char *file)
{
	char	*rev;

	rev = ft_strdup(file);
	ft_reverse(rev);
	if (ft_strncmp(rev, "reb.", 4))
		return (free(rev), 0);
	return (free(rev), 1);
}

//Additional function for ft_check_map_chars
static int	ft_bools(char c, bool *player, bool *exit, bool *collectibles)
{
	if ((!ft_is_charset(c, "01PECX")) || (c == 'P' && *player) || (c == 'E'
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

//Checks if chars in the map are either 0/1/P/E/C and
//if there's one player, one exit and at least one collectible
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

//Checks if the map is a rectangle
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

//Checks if the map is surrounded by walls
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
