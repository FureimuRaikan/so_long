/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:28:14 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/28 09:03:20 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Initialises the mlx and create its window (size ajusted to the map size)
int	ft_mlx_init(t_solong *solong)
{
	int const	tile_size = TILE_SIZE;

	solong->ptr = mlx_init();
	if (!solong->ptr)
		return (0);
	solong->win = mlx_new_window(solong->ptr, solong->map_size.x * tile_size,
			solong->map_size.y * tile_size, "so_long");
	if (!solong->win)
		return (mlx_destroy_display(solong->ptr), 0);
	ft_store_assets(solong);
	solong->lose = 0;
	solong->foe_nb = ft_foe_nb(solong->map);
	solong->frame = 0;
	ft_alloc_foe(solong);
	return (1);
}

//Closes the window and the mlx and free the map
int	ft_mlx_close(t_solong *solong)
{
	ft_destroy_images(solong, solong->assets.player_left, "assets/player_left");
	ft_destroy_images(solong, solong->assets.player_right,
		"assets/player_right");
	ft_destroy_images(solong, solong->assets.player_left_ex,
		"assets/player_left_ex");
	ft_destroy_images(solong, solong->assets.player_right_ex,
		"assets/player_right_ex");
	ft_destroy_images(solong, solong->assets.wall, "assets/wall");
	ft_destroy_images(solong, solong->assets.item, "assets/item");
	ft_destroy_images(solong, solong->assets.exit, "assets/exit");
	ft_destroy_images(solong, solong->assets.score, "assets/score");
	ft_destroy_images(solong, solong->assets.vegeta, "assets/vegeta");
	ft_destroy_images(solong, solong->assets.win, "assets/win");
	ft_destroy_images(solong, solong->assets.foe_l, "assets/foe_l");
	ft_destroy_images(solong, solong->assets.foe_r, "assets/foe_r");
	mlx_destroy_image(solong->ptr, solong->assets.grass.img_ptr);
	mlx_destroy_image(solong->ptr, solong->assets.lose.img_ptr);
	mlx_destroy_window(solong->ptr, solong->win);
	mlx_destroy_display(solong->ptr);
	free(solong->ptr);
	free(solong->foes);
	if (solong->map)
		ft_free_split(solong->map);
	exit(0);
}
