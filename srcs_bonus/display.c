/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:25:34 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/28 09:27:32 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_display_vegeta(t_solong solong, t_point coords)
{
	mlx_put_image_to_window(solong.ptr, solong.win,
		solong.assets.vegeta[(solong.frame / 100) % 4].img_ptr,
		coords.x, coords.y);
}

//Displays the score player at the top of the map
void	ft_display_score(t_solong solong)
{
	char		*score;
	t_point		coords;
	int			i;
	int const	tile_size = TILE_SIZE;

	ft_set_coordinates(&coords, (tile_size / 4), tile_size / 4);
	mlx_put_image_to_window(solong.ptr, solong.win,
		solong.assets.score[10].img_ptr, coords.x, coords.y);
	coords.x += solong.assets.score[10].w;
	if (solong.count > 9000)
	{
		solong.count = 9001;
		ft_display_vegeta(solong, coords);
		return ;
	}
	score = ft_itoa(solong.count);
	i = -1;
	while (score[++i])
	{
		mlx_put_image_to_window(solong.ptr, solong.win,
			solong.assets.score[score[i] - 48].img_ptr, coords.x, coords.y);
		coords.x += (tile_size / 2);
	}
	free(score);
}

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
	ft_display_tile(*solong, '0', solong->assets.grass.img_ptr);
	ft_display_tile(*solong, '1',
		solong->assets.wall[(solong->frame / 200) % 8].img_ptr);
	ft_display_tile(*solong, 'C',
		solong->assets.item[(solong->frame / 80) % 4].img_ptr);
	ft_display_player(solong, solong->frame);
	if (ft_is_collectibles(solong->map))
		ft_display_tile(*solong, 'E', solong->assets.exit[0].img_ptr);
	else
		ft_display_tile(*solong, 'E', solong->assets.exit[1].img_ptr);
	ft_display_score(*solong);
	ft_display_foes(solong, solong->frame);
	if (solong->frame % 100 == 0)
		ft_move_enemy(solong, solong->foes);
	if (ft_check_win(solong) || solong->lose)
		ft_display_ending_screen(solong);
	solong->frame++;
	if (solong->frame == 1600)
		solong->frame = 0;
	return (1);
}
