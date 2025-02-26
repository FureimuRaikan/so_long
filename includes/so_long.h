/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:59 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/24 16:31:58 by fureimu          ###   ########.fr       */
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

# define TILE_SIZE 64

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	t_point			cords;
	bool			side;
}				t_player;

enum e_keys
{
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

typedef struct s_assets
{
	t_img	player_left[4];
	t_img	player_right[4];
	t_img	player_left_ex[4];
	t_img	player_right_ex[4];
	t_img	grass;
	t_img	wall[8];
	t_img	exit[2];
	t_img	item[4];
}			t_assets;

typedef struct s_mlx_data
{
	void		*ptr;
	void		*win;
	t_player	player;
	char		**map;
	t_point		map_size;
	t_point		exit;
	int			count;
	int			frame;
	t_assets	assets;
}				t_solong;

void	ft_print_rules(int out_fd);

void	ft_args_checks(int ac, char **av);

void	ft_check_map(t_solong *solong);
int		ft_map_is_ber(char *map);
int		ft_is_explorable(t_solong *solong);
int		ft_check_map_chars(char **map);
int		ft_check_walls(char **map);
int		ft_check_map_shape(char **map);
void	ft_exit_error(char *Error_message, char **map);

void	ft_parse_map(t_solong *solong, char *file);
int		ft_mlx_init(t_solong *solong);
int		ft_mlx_close(t_solong *solong);

int		ft_handle_input(int key, t_solong *solong);
int		ft_move_player(int key, t_solong *solong);
t_point	ft_find_coordinates(char c, char **map);
t_point	ft_create_coordinates(int x, int y);
int		ft_display_map(t_solong *solong);
int		ft_is_same_coordinates(t_point a, t_point b);
bool	ft_is_collectibles(char **map);

void	ft_display_tile(t_solong solong, char tile, void *img);
void	ft_check_win(t_solong *solong);

void	ft_map_size(t_solong *solong);
void	ft_set_coordinates(t_point *point, int x, int y);
void	ft_copy_coordinates(t_point a, t_point *b);

void	ft_store_assets(t_solong *solong);
void	ft_update_map(t_solong solong, char **old_version);
void	ft_create_transparent_image(t_solong *solong,
			void **img, int width, int height);
void	ft_store_images(t_solong solong, t_img *asset, char *asset_dir,
			char *filename);
void	ft_store_assets(t_solong *solong);
void	ft_destroy_images(t_solong *solong, t_img *asset, char *filename);

#endif