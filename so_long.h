/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:40:18 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/01 15:37:11 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define MLX_ERROR 1
# define ExitButton 17
# define KeyPress 2

# define SIZE_IMG 64

//# define PLAYER_FRONT "sprites/player/player_front.xpm"
//# define PLAYER_BACK "sprites/player/player_back.xpm"
# define PLAYER_RIGHT "sprites/player/p_right.xpm"
# define PLAYER_LEFT "sprites/player/p_left.xpm"
# define EXIT_CLOSE "sprites/exit/exit_close.xpm"
# define EXIT_OPEN "sprites/exit/exit_open.xpm"
# define PATH "sprites/background/mid1.xpm"
# define WALL "sprites/background/obst1.xpm"
# define COLECT "sprites/colectible/colect.xpm"

typedef struct s_point {
	int	x;
	int	y;
}		t_point;

typedef struct s_img {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	t_point	size;
	int		endian;
	char	*path;
}	t_img;

typedef struct s_sprite {
	// void	*img_player_front;
	// void	*img_player_back;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_path;
	void	*img_wall;
	void	*img_colect;

}	t_sprite;

typedef struct s_game {
	char		**map;
	// int			moves;
	int			colectible;
	int			start;
	int			exit;
	t_point		p;
	void		*mlx;
	void		*win;
	t_img		simg;
	int			width;
	int			height;
	t_sprite	xpm;
}	t_game;

/* Utils */
void	set_on_null(t_game *game);
void	error_message(char *str, t_game *game);

/* Map checker */
void	check_filename(int argc, char *mapfile, t_game *game);
void	linecount(char *mapfile, t_game *game);
void	create_map(char *mapfile, t_game *game);
void	check_map_elements(char **map, t_game *game);
void	check_map_stucture(char **map, t_game *game);

/* Map playable */
void	flood_fill(t_game *game);
void	fill(char **map, t_point size, t_point cur, char to_fill);


void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_game *data);
int		close_window(t_game *data);

int		put_images(t_game *data);
void	load_images(t_game *data);

#endif
