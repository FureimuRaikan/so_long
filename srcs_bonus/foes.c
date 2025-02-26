/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:50:17 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/26 15:16:52 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

//Moves the ememy if the next tile is empty, according to its direction
void	ft_move_foe(t_solong *solong, t_player *foe, int i, int dir)
{
	t_point	p;

	ft_copy_coordinates(foe[i].cords, &p);
	if (solong->map[p.y][p.x + dir] == 'P' && !ft_check_win(solong))
	{
		solong->lose = 1;
		solong->map[p.y][p.x + dir] = '0';
	}
	if (solong->map[p.y][p.x + dir] == '0')
	{
		solong->map[p.y][p.x] = '0';
		solong->map[p.y][p.x + dir] = 'X';
		ft_set_coordinates(&solong->foes[i].cords, p.x + dir, p.y);
		if (solong->map[p.y][p.x + (dir * 2)] != '0'
			&& solong->map[p.y][p.x + (dir * 2)] != 'P')
			foe[i].side = 1 - foe[i].side;
	}
}

//Moves the enemies on the map
void	ft_move_enemy(t_solong *solong, t_player *foe)
{
	int	i;
	int	dir;

	i = -1;
	while (++i < solong->foe_nb)
	{
		if (solong->map[foe[i].cords.y][foe[i].cords.x + 1] == 'X')
		{
			foe[i + 1].side = 1;
			foe[i].side = 0;
		}
		dir = -1;
		if (foe[i].side == 1)
			dir = 1;
		ft_move_foe(solong, foe, i, dir);
	}
}

//Allocates memory for a t_player array for enemies and sets their positions
void	ft_alloc_foe(t_solong *solong)
{
	int			count;
	t_point		cords;

	solong->foes = (t_player *)ft_calloc(sizeof(t_player), solong->foe_nb);
	if (!solong->foes)
		return ;
	count = 0;
	ft_set_coordinates(&cords, -1, -1);
	while (solong->map[++cords.y] && count < solong->foe_nb)
	{
		cords.x = -1;
		while (solong->map[cords.y][++cords.x] && count < solong->foe_nb)
		{
			if (solong->map[cords.y][cords.x] == 'X')
			{
				ft_set_coordinates(&solong->foes[count].cords,
					cords.x, cords.y);
				ft_printf("%i foe at x: %i, y: %i\n", count, solong->foes[count].cords.x, solong->foes[count].cords.y);
				count++;
			}
		}
	}
	ft_foe_side(solong);
}

//Sets the starting side of the enemies
void	ft_foe_side(t_solong *solong)
{
	int	count;

	count = 0;
	while (count < solong->foe_nb)
	{
		if (solong->foes[count].cords.x < solong->map_size.x / 2)
			solong->foes[count].side = 1;
		else
			solong->foes[count].side = 0;
		count++;
	}
}

//Displays the en;ies on the map
void	ft_display_foes(t_solong *solong, int frame)
{
	int		i;

	i = 0;
	while (i < solong->foe_nb)
	{
		if (solong->foes[i].side == 0)
			mlx_put_image_to_window(solong->ptr, solong->win,
				solong->assets.foe_l[(frame / 100) % 4].img_ptr,
				solong->foes[i].cords.x * TILE_SIZE, solong->foes[i].cords.y
				* TILE_SIZE);
		else
			mlx_put_image_to_window(solong->ptr, solong->win,
				solong->assets.foe_r[(frame / 100) % 4].img_ptr,
				solong->foes[i].cords.x * TILE_SIZE, solong->foes[i].cords.y
				* TILE_SIZE);
		i++;
	}
}
