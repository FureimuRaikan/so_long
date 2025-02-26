/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:38:50 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/24 12:57:54 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
void	ft_check_win(t_solong *solong)
{
	if (ft_is_same_coordinates(solong->player.cords, solong->exit)
		&& !ft_is_collectibles(solong->map))
	{
		if (solong->count > 9000)
			ft_printf("\rCongratulations ! You won !\nYour score is over \
9000 !!!!!\n", solong->count);
		else
			ft_printf("\rCongratulations ! You won !\nYour score is: %i\n",
				solong->count);
		solong->map[solong->player.cords.y][solong->player.cords.x] = 'P';
		ft_mlx_close(solong);
	}
}
