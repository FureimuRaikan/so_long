/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:26:20 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/28 08:53:28 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Checks if given map is correct and parse it into a char** using split function
void	ft_parse_map(t_solong *solong, char *file)
{
	int		fd;
	char	*file_content;
	char	*line;

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
	solong->map = ft_split(file_content, '\n');
	free(file_content);
	close(fd);
	ft_map_size(solong);
	solong->count = 0;
	ft_check_map(solong);
}
