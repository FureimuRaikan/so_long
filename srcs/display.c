/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:25:34 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/24 12:31:37 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Displays filename image at every tile in the map
void	ft_display_tile(t_solong solong, char tile, void *img)
{
	int			x;
	int			y;
	int const	tile_size = TILE_SIZE;

	y = -1;
	while (solong.map[++y])
	{
		x = -1;
		while (solong.map[y][++x])
			if (solong.map[y][x] == tile)
				mlx_put_image_to_window(solong.ptr, solong.win, img,
					x * tile_size, y * tile_size);
	}
}

//Displays player animation
void	ft_display_player(t_solong *solong, int frame)
{
	if (solong->player.side == 0)
	{
		if (ft_is_same_coordinates(solong->player.cords, solong->exit))
			ft_display_tile(*solong, 'P',
				solong->assets.player_left_ex[(frame / 100) % 4].img_ptr);
		else
			ft_display_tile(*solong, 'P',
				solong->assets.player_left[(frame / 100) % 4].img_ptr);
	}
	if (solong->player.side == 1)
	{
		if (ft_is_same_coordinates(solong->player.cords, solong->exit))
			ft_display_tile(*solong, 'P',
				solong->assets.player_right_ex[(frame / 100) % 4].img_ptr);
		else
			ft_display_tile(*solong, 'P',
				solong->assets.player_right[(frame / 100) % 4].img_ptr);
	}
}

//Displays the whole map
int	ft_display_map(t_solong *solong)
{
	static int	frame;

	ft_display_tile(*solong, '0', solong->assets.grass.img_ptr);
	ft_display_tile(*solong, '1',
		solong->assets.wall[(frame / 200) % 8].img_ptr);
	ft_display_tile(*solong, 'C',
		solong->assets.item[(frame / 80) % 4].img_ptr);
	ft_display_player(solong, frame);
	if (ft_is_collectibles(solong->map))
		ft_display_tile(*solong, 'E', solong->assets.exit[0].img_ptr);
	else
		ft_display_tile(*solong, 'E', solong->assets.exit[1].img_ptr);
	solong->frame = frame;
	frame++;
	if (frame == 1600)
		frame = 0;
	return (1);
}
