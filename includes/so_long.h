/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:59 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/14 18:52:12 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <errno.h>
# include <stdio.h>

# define TILE_SIZE 32

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_player
{
	t_point			cords;
	int				items;
	unsigned long	key;
}				t_player;

enum e_keys {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100
} ;

typedef struct s_mlx_data
{
	void		*ptr;
	void		*win;
}				t_mlx_data;

void	ft_print_rules(int out_fd);

int		ft_map_is_ber(char *map);
char	**ft_parse_map(char *file);
void	ft_check_map(char **map);
int		ft_is_explorable(char **map);
int		ft_map_exemple(char **map);
int		ft_check_map_chars(char **map);


void	ft_exit_error(char *Error_message, char **map);

t_point	ft_map_size(char **map);
void	ft_coordinates(t_point *point, int x, int y);

int	ft_put_image(t_mlx_data mlx, char *filename, t_point img_size,
		t_point img_position);

int		ft_mlx_init(t_mlx_data *mlx_data, char **map);

#endif