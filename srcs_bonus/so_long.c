/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:46 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/28 08:57:50 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_solong	solong;

	ft_args_checks(ac, av);
	solong.map_path = av[1];
	ft_parse_map(&solong);
	ft_mlx_init(&solong);
	ft_display_map(&solong);
	mlx_loop_hook(solong.ptr, ft_display_map, &solong);
	mlx_hook(solong.win, ON_KEYDOWN, KeyPressMask, ft_handle_input, &solong);
	mlx_hook(solong.win, ON_DESTROY, 0, ft_mlx_close, &solong);
	mlx_loop(solong.ptr);
	return (0);
}
