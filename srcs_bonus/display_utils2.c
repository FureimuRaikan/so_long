/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:45:40 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/27 10:46:00 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Destroys all images of the given asset filename
void	ft_destroy_images(t_solong *solong, t_img *asset, char *filename)
{
	char		*file;
	char		*file_nb;
	int			i;
	int			fd;

	i = 0;
	file_nb = ft_itoa(i);
	file = ft_strjoin_free(ft_strjoin(filename, file_nb), ".xpm");
	free(file_nb);
	fd = open(file, O_RDONLY);
	while (fd != -1)
	{
		close(fd);
		mlx_destroy_image(solong->ptr, asset[i].img_ptr);
		i++;
		free(file);
		file_nb = ft_itoa(i);
		file = ft_strjoin_free(ft_strjoin(filename, file_nb), ".xpm");
		free(file_nb);
		fd = open(file, O_RDONLY);
	}
	free(file);
}
