/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:26:32 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/14 18:20:52 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_init(t_mlx_data *mlx_data, char **map)
{
	t_point	map_size;
	int		x;
	int		y;

	map_size = ft_map_size(map);
	mlx_data->ptr = mlx_init();
	if (!mlx_data->ptr)
		return (0);
	mlx_get_screen_size(mlx_data->ptr, &x, &y);
	mlx_data->win = mlx_new_window(mlx_data->ptr, x, y - 70, "so_long");
	if (!mlx_data->win)
		return (mlx_destroy_display(mlx_data->ptr), 0);
	return (1);
}
