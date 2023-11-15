/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:40:18 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/14 15:12:40 by lkoletzk         ###   ########.fr       */
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
# include <errno.h>

# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define EXIT 17
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define SIZE_IMG 64

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
	int		endian;
	t_point	size;
}	t_img;

typedef struct s_sprite {
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
	int			moves;
	int			colectible;
	int			start;
	int			exit;
	t_point		p_exit;
	t_point		p_perso;
	int			end_game;
	void		*mlx;
	void		*win;
	t_img		img;
	int			width;
	int			height;
	t_sprite	xpm;

}	t_game;

/* Utils */
void	free_map(t_game *game);
int		close_window(t_game *game, int key);
void	set_on_null(t_game *game);
void	error_message(char *str, t_game *game);

/* Map checker */
void	check_filename(int argc, char *mapfile, t_game *game);
void	create_map(char *mapfile, t_game *game);
void	check_map_elements(char **map, t_game *game);
void	check_map_stucture(char **map, t_game *game);

/* Map solvability */
void	flood_fill(t_game *game);

/* Player's moves */
int		key_map(int key, t_game *game);

/* Graphismes */
int		put_images(t_game *game, int key);
void	load_images(t_game *game);

#endif
