/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:07:46 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/24 15:59:45 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Stores an XPM file into a t_img struct
t_img	ft_new_file_img(t_solong solong, char *path)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(solong.ptr, path, &image.w, &image.h);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
				&(image.line_len), &(image.endian));
	return (image);
}

//Stores multiples XPM files into a t_img array
void	ft_store_images(t_solong solong, t_img *asset, char *assets_dir,
	char *filename)
{
	char		*file;
	char		*file_nb;
	int			i;
	int			fd;

	i = 0;
	filename = ft_strjoin(assets_dir, filename);
	file_nb = ft_itoa(i);
	file = ft_strjoin_free(ft_strjoin(filename, file_nb), ".xpm");
	free(file_nb);
	fd = open(file, O_RDONLY);
	while (fd != -1)
	{
		close(fd);
		asset[i] = ft_new_file_img(solong, file);
		i++;
		free(file);
		file_nb = ft_itoa(i);
		file = ft_strjoin_free(ft_strjoin(filename, file_nb), ".xpm");
		free(file_nb);
		fd = open(file, O_RDONLY);
	}
	free(filename);
	free(file);
}

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

//Stores all the assets needed for so_long
void	ft_store_assets(t_solong *solong)
{
	char		*asset_dir;
	int const	tile_size = TILE_SIZE;

	if (tile_size == 32)
		asset_dir = ft_strdup("assets32/");
	else
		asset_dir = ft_strdup("assets/");
	ft_store_images(*solong, solong->assets.player_left, asset_dir,
		"player_left");
	ft_store_images(*solong, solong->assets.player_left_ex, asset_dir,
		"player_left_ex");
	ft_store_images(*solong, solong->assets.player_right, asset_dir,
		"player_right");
	ft_store_images(*solong, solong->assets.player_right_ex, asset_dir,
		"player_right_ex");
	ft_store_images(*solong, solong->assets.wall, asset_dir, "wall");
	ft_store_images(*solong, solong->assets.exit, asset_dir, "exit");
	ft_store_images(*solong, solong->assets.item, asset_dir, "item");
	asset_dir = ft_strjoin_free(asset_dir, "grass.xpm");
	solong->assets.grass = ft_new_file_img(*solong, asset_dir);
	free(asset_dir);
}
