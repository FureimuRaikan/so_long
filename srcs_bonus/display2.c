/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:29:18 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/26 15:26:16 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Displays the ending screen
void	ft_display_ending_screen(t_solong *solong)
{
	if (ft_check_win(solong))
		mlx_put_image_to_window(solong->ptr, solong->win,
			solong->assets.win[(solong->frame / 50 % 4)].img_ptr,
			((solong->map_size.x * TILE_SIZE) - solong->assets.win[0].w) / 2,
			((solong->map_size.y * TILE_SIZE) - solong->assets.win[0].h) / 2);
	if (solong->lose)
		mlx_put_image_to_window(solong->ptr, solong->win, solong->assets.lose.img_ptr,
			((solong->map_size.x * TILE_SIZE) - solong->assets.lose.w) / 2,
			((solong->map_size.y * TILE_SIZE) - solong->assets.lose.h) / 2);
}
