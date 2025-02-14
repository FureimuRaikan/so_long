/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:46 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/14 18:54:55 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_mlx_data *mlx_data)
{
	mlx_destroy_window(mlx_data->ptr, mlx_data->win);
	mlx_destroy_display(mlx_data->ptr);
	free(mlx_data->ptr);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_input(int key, t_mlx_data *data)
{
	if (key == XK_Escape || key == 113)
		ft_close(data);
	else
		ft_putnbr_len(key);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx_data	solong;
	char		**map;
	// t_data		img;

	if (ac < 2 || av[1][0] == 0)
		return (ft_putendl_fd("Error\n\nNo map.", 2), ft_print_rules(2), 2);
	if (!ft_map_is_ber(av[1]))
		return (ft_putendl_fd("Error\n\nMap must be a .ber file", 2),
			ft_print_rules(2), 1);
	if (ac > 2)
		return (ft_putendl_fd("Error\n\nToo many arguments.", 2),
			ft_print_rules(2), 1);
	map = ft_parse_map(av[1]);
	ft_mlx_init(&solong, map);
	ft_free_split(map);
	mlx_loop_hook(solong.ptr, handle_no_event, &solong);
	mlx_hook(solong.win, ON_DESTROY, 0, ft_close, &solong);
	mlx_key_hook(solong.win, handle_input, &solong);
	t_point	img_size;
	img_size.x = 0;
	img_size.y = 0;
	t_point	img_position;
	img_position.x = 50;
	img_position.y = 50;
	ft_put_image(solong, "Untitled.xpm", img_size, img_position);
	mlx_loop(solong.ptr);
	mlx_destroy_display(solong.ptr);
	free(solong.ptr);
	return (ft_free_split(map), 0);
}
 