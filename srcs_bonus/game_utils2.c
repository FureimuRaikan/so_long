/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:38:50 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/28 09:25:09 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Checks if both t_point are at the same coordinates
int	ft_is_same_coordinates(t_point a, t_point b)
{
	if (a.x == b.x && a.y == b.y)
		return (1);
	return (0);
}

//Copies the coordinates from a to b
void	ft_copy_coordinates(t_point a, t_point *b)
{
	b->x = a.x;
	b->y = a.y;
}

//Checks if the player is on the exit tile and has collected all items
int	ft_check_win(t_solong *solong)
{
	if (ft_is_same_coordinates(solong->player.cords, solong->exit)
		&& !ft_is_collectibles(solong->map))
		return (1);
	return (0);
}

//Checks if the player is trying to access a tile occupied by an enemy
//If so, switches solong.lose to true
void	ft_check_lose_player(int key, t_solong *solong)
{
	if ((key == XK_w || key == XK_Up)
		&& solong->map[solong->player.cords.y - 1][solong->player.cords.x]
		== 'X' && solong->player.cords.y > 0)
		solong->lose = 1;
	if ((key == XK_s || key == XK_Down)
		&& solong->map[solong->player.cords.y + 1][solong->player.cords.x]
			== 'X' && solong->player.cords.y < solong->map_size.y)
		solong->lose = 1;
	if (key == XK_a || key == XK_Left)
	{
		solong->player.side = 0;
		if (solong->map[solong->player.cords.y][solong->player.cords.x - 1]
		== 'X' && solong->player.cords.x > 0)
			solong->lose = 1;
	}
	if (key == XK_d || key == XK_Right)
	{
		solong->player.side = 1;
		if (solong->map[solong->player.cords.y][solong->player.cords.x + 1]
			== 'X' && solong->player.cords.x < solong->map_size.x)
			solong->lose = 1;
	}
}

//Reinitialize the game
void	ft_reinit_game(t_solong *solong)
{
	ft_free_split(solong->map);
	ft_parse_map(solong);
	free(solong->foes);
	ft_alloc_foe(solong);
	solong->count = 0;
	solong->lose = 0;
	solong->frame = 0;
}
