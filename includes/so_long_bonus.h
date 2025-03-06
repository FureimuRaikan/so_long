/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:59 by yguinio           #+#    #+#             */
/*   Updated: 2025/03/04 14:33:04 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <errno.h>
# include <stdio.h>

# define TILE_SIZE 32

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
	t_img	win[4];
	t_img	lose;
	t_img	wall[8];
	t_img	exit[2];
	t_img	item[4];
	t_img	vegeta[4];
	t_img	score[11];
	t_img	foe_l[4];
	t_img	foe_r[4];
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
	bool		lose;
	int			foe_nb;
	t_player	*foes;
	char		*map_path;
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

void	ft_parse_map(t_solong *solong);
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
int		ft_check_win(t_solong *solong);

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
void	ft_move_enemy(t_solong *solong, t_player *foe);
void	ft_foe_side(t_solong *solong);
void	ft_alloc_foe(t_solong *solong);
void	ft_display_foes(t_solong *solong, int frame);
int		ft_foe_nb(char **map);
void	ft_check_lose_player(int key, t_solong *solong);
void	ft_display_ending_screen(t_solong *solong);
void	ft_reinit_game(t_solong *solong);

#endif