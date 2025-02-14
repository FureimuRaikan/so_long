/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:59:18 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/12 15:49:16 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_mlx_data *mlx_data)
{
	mlx_data->ptr = mlx_init();
	if (!mlx_data->ptr)
		exit(EXIT_FAILURE);
	mlx_data->win = mlx_new_window(mlx_data->ptr, 800, 600, "so_long");
	if (!mlx_data->win)
	{
		mlx_destroy_display(mlx_data->ptr);
		free(mlx_data->ptr);
		exit(EXIT_FAILURE);
	}
}
