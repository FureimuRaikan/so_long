/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:23:42 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/14 18:49:31 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_put_image(t_mlx_data mlx, char *filename, t_point img_size,
		t_point img_position)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx.ptr, filename, &img_size.x, &img_size.y);
	if (!img)
		return (0);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img, img_position.x,
		img_position.y);
	return (1);
}
