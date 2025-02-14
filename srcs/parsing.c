/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:26:20 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/12 18:08:51 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_parse_map(char *file)
{
	int		fd;
	char	*file_content;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
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
	map = ft_split(file_content, '\n');
	free(file_content);
	close(fd);
	return (ft_check_map(map), map);
}
