/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:41:44 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/14 12:16:46 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_rules(int out_fd)
{
	int		fd;
	char	*line;

	(void)out_fd;
	fd = open("rules.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Rules open");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_putstr_fd(line, 2);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
