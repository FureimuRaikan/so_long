/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:40:03 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/24 15:37:00 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Floods the map from starting point with 'A'
static void	ft_flood_fill(char **tab, t_point size, t_point begin)
{
	t_point	p;

	if (tab[begin.y][begin.x] == 'A')
		return ;
	tab[begin.y][begin.x] = 'A';
	if (begin.y > 0 && tab[begin.y - 1][begin.x] != '1')
	{
		ft_set_coordinates(&p, begin.x, begin.y - 1);
		ft_flood_fill(tab, size, p);
	}
	if ((begin.y < (size.y - 1)) && tab[begin.y + 1][begin.x] != '1')
	{
		ft_set_coordinates(&p, begin.x, begin.y + 1);
		ft_flood_fill(tab, size, p);
	}
	if ((begin.x < (size.x - 1)) && tab[begin.y][begin.x + 1] != '1')
	{
		ft_set_coordinates(&p, begin.x + 1, begin.y);
		ft_flood_fill(tab, size, p);
	}
	if (begin.x > 0 && tab[begin.y][begin.x - 1] != '1')
	{
		ft_set_coordinates(&p, begin.x - 1, begin.y);
		ft_flood_fill(tab, size, p);
	}
}

//Sets the player starting position and the exit position then
//checks if every collectible and the exit are reachable by the player
int	ft_is_explorable(t_solong *solong)
{
	char	**temp_map;
	int		i;
	int		j;

	temp_map = ft_array_str_dup(solong->map);
	if (!temp_map)
		return (0);
	solong->player.cords.x = ft_find_coordinates('P', temp_map).x;
	solong->player.cords.y = ft_find_coordinates('P', temp_map).y;
	if (solong->player.cords.x < solong->map_size.x / 2)
		solong->player.side = 1;
	else
		solong->player.side = 0;
	solong->exit.x = ft_find_coordinates('E', temp_map).x;
	solong->exit.y = ft_find_coordinates('E', temp_map).y;
	ft_flood_fill(temp_map, solong->map_size, solong->player.cords);
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

//Prints the error message to the error output and free the map
void	ft_exit_error(char *Error_message, char **map)
{
	ft_putendl_fd(Error_message, 2);
	ft_print_rules(2);
	if (map)
		ft_free_split(map);
	exit(1);
}

//Checks every possible error concerning map and exit if an error is detected
void	ft_check_map(t_solong *solong)
{
	if (!solong->map || !solong->map[0])
		ft_exit_error("Error\n\nEmpty map.", solong->map);
	if (!ft_check_map_chars(solong->map))
		ft_exit_error("Error\nMap must only contain 0/1/P/E/C\n\
0: empty tile\n1: wall\nP: starting position (unique)\nE: exit (unique)\nC:\
 collectibles (1 minimum)", solong->map);
	if (!ft_check_map_shape(solong->map))
		ft_exit_error("Map must be a rectangle.", solong->map);
	if (!ft_check_walls(solong->map))
		ft_exit_error("Error\n\nMap must be surrounded by walls.", solong->map);
	if (!ft_is_explorable(solong))
		ft_exit_error("Error\n\nExit and Collectibles must be reachable by the\
 player.", solong->map);
}

//Checks if the given argument is valid
void	ft_args_checks(int ac, char **av)
{
	if (ac < 2 || av[1][0] == 0)
	{
		ft_putendl_fd("Error\n\nNo map.", 2);
		ft_print_rules(2);
		exit(1);
	}
	if (!ft_map_is_ber(av[1]))
	{
		ft_putendl_fd("Error\n\nMap must be a .ber file", 2);
		ft_print_rules(2);
		exit(1);
	}
	if (ac > 2)
	{
		ft_putendl_fd("Error\n\nToo many arguments.", 2);
		ft_print_rules(2);
		exit(1);
	}
}
