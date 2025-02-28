/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:15:38 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/28 09:25:49 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Moves the player accordingly to the pressed key
int	ft_resolve_player_move(int key, t_solong *solong)
{
	t_point	temp;

	ft_copy_coordinates(solong->player.cords, &temp);
	if (ft_is_same_coordinates(solong->player.cords, solong->exit))
		solong->map[solong->player.cords.y][solong->player.cords.x] = 'E';
	else
		solong->map[solong->player.cords.y][solong->player.cords.x] = '0';
	if (key == XK_w || key == XK_Up)
		solong->player.cords.y -= 1;
	if (key == XK_s || key == XK_Down)
		solong->player.cords.y += 1;
	if (key == XK_a || key == XK_Left)
		solong->player.cords.x -= 1;
	if (key == XK_d || key == XK_Right)
		solong->player.cords.x += 1;
	solong->count++;
	solong->map[solong->player.cords.y][solong->player.cords.x] = 'P';
	return (1);
}

//Checks if the conditions of player movement are met
int	ft_move_player(int key, t_solong *solong)
{
	if ((key == XK_w || key == XK_Up)
		&& solong->map[solong->player.cords.y - 1][solong->player.cords.x]
			!= '1' && solong->player.cords.y > 0)
		ft_resolve_player_move(key, solong);
	if ((key == XK_s || key == XK_Down)
		&& solong->map[solong->player.cords.y + 1][solong->player.cords.x]
			!= '1' && solong->player.cords.y < solong->map_size.y)
		ft_resolve_player_move(key, solong);
	if (key == XK_a || key == XK_Left)
	{
		solong->player.side = 0;
		if (solong->map[solong->player.cords.y][solong->player.cords.x - 1]
		!= '1' && solong->player.cords.x > 0)
			ft_resolve_player_move(key, solong);
	}
	if (key == XK_d || key == XK_Right)
	{
		solong->player.side = 1;
		if (solong->map[solong->player.cords.y][solong->player.cords.x + 1]
			!= '1' && solong->player.cords.x < solong->map_size.x)
			ft_resolve_player_move(key, solong);
	}
	return (1);
}

//Checks if the pressed key triggers an action
int	ft_handle_input(int key, t_solong *solong)
{
	if (key == XK_Escape || key == 113)
		ft_mlx_close(solong);
	if (ft_check_win(solong) || solong->lose)
	{
		if (key == XK_r)
			ft_reinit_game(solong);
		return (0);
	}
	if ((key == XK_w || key == XK_Up) || (key == XK_s || key == XK_Down)
		|| (key == XK_a || key == XK_Left) || (key == XK_d || key == XK_Right))
	{
		ft_check_lose_player(key, solong);
		ft_move_player(key, solong);
	}
	return (0);
}
