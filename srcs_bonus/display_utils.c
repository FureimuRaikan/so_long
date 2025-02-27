/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:07:46 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/27 10:45:25 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

//Chooses the right directory for the assets
char	*ft_asset_dir(void)
{
	char	*asset_dir;

	if (TILE_SIZE == 32)
		asset_dir = ft_strdup("assets32/");
	else
		asset_dir = ft_strdup("assets/");
	return (asset_dir);
}

//Subfuction of ft_store_assets
static void	ft_sub_store_assets(t_solong *solong, char *asset_dir)
{
	char	*temp;

	temp = ft_strjoin(asset_dir, "grass.xpm");
	solong->assets.grass = ft_new_file_img(*solong, temp);
	free(temp);
	temp = ft_strjoin(asset_dir, "lose0.xpm");
	solong->assets.lose = ft_new_file_img(*solong, temp);
	free(temp);
}

//Stores all the assets needed for so_long
void	ft_store_assets(t_solong *solong)
{
	char		*asset_dir;

	asset_dir = ft_asset_dir();
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
	ft_store_images(*solong, solong->assets.score, asset_dir, "score");
	ft_store_images(*solong, solong->assets.vegeta, asset_dir, "vegeta");
	ft_store_images(*solong, solong->assets.win, asset_dir, "win");
	ft_store_images(*solong, solong->assets.foe_l, asset_dir, "foe_l");
	ft_store_images(*solong, solong->assets.foe_r, asset_dir, "foe_r");
	ft_sub_store_assets(solong, asset_dir);
	free(asset_dir);
}
