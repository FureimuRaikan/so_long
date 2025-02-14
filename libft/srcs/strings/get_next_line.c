/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:11:22 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/05 14:37:00 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd, char *str_stored)
{
	char	buff[BUFFER_SIZE + 1];
	int		count;

	count = 1;
	while (!ft_strchr(str_stored, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			if (str_stored)
			{
				free(str_stored);
				str_stored = NULL;
			}
			return (NULL);
		}
		buff[count] = 0;
		str_stored = ft_strjoin_free(str_stored, buff);
	}
	return (str_stored);
}

char	*ft_line(char *str_stored)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str_stored[i])
		return (NULL);
	while (str_stored[i] && str_stored[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str_stored[i] && str_stored[i] != '\n')
	{
		line[i] = str_stored[i];
		i++;
	}
	if (str_stored[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *str_stored)
{
	char	*next;
	int		i;
	int		j;
	size_t	str_stored_len;

	i = 0;
	j = 0;
	str_stored_len = ft_strlen(str_stored);
	while (str_stored[i] && str_stored[i] != '\n')
		i++;
	if (!str_stored[i])
	{
		free(str_stored);
		str_stored = NULL;
		return (NULL);
	}
	next = ft_calloc((str_stored_len - i + 1), sizeof(char));
	if (!next)
		return (NULL);
	while (str_stored[++i])
		next[j++] = str_stored[i];
	next[j] = 0;
	free(str_stored);
	return (next);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str_stored[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_stored[fd] = ft_read_file(fd, str_stored[fd]);
	if (!str_stored[fd])
	{
		str_stored[fd] = NULL;
		return (NULL);
	}
	line = ft_line(str_stored[fd]);
	str_stored[fd] = ft_next_line(str_stored[fd]);
	return (line);
}
