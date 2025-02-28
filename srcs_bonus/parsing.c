/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:26:20 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/28 08:57:25 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Returns the number of enemies present on the map
int	ft_foe_nb(char **map)
{
	int	x;
	int	y;
	int	nb;

	nb = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'X')
				nb++;
	}
	return (nb);
}

//Checks if given map is correct and parse it into a char** using split function
void	ft_parse_map(t_solong *solong)
{
	int		fd;
	char	*file_content;
	char	*line;

	fd = open(solong->map_path, O_RDONLY);
	if (fd == -1)
	{
		perror(solong->map_path);
		exit (1);
	}
	file_content = ft_calloc(sizeof(char), 1);
	line = get_next_line(fd);
	while (line)
	{
		file_content = ft_strjoin_free(file_content, line);
		free(line);
		line = get_next_line(fd);
	}
	solong->map = ft_split(file_content, '\n');
	ft_map_size(solong);
	solong->count = 0;
	solong->foe_nb = ft_foe_nb(solong->map);
	free(file_content);
	close(fd);
	ft_check_map(solong);
}
