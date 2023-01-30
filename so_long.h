/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:40:18 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/01/30 13:47:12 by lkoletzk         ###   ########.fr       */
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

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

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
	// t_sprite	xpm;
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


int	mlxpart(t_game *game);
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_game *data);
#endif
