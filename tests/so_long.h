/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:43:09 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/01/30 13:57:36 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define MLX_ERROR 1

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win;
	t_img	simg;
}	t_data;


// /* vector with an x and y */
// typedef struct	s_vector
// {
// 	int	x;
// 	int	y;
// }				t_vector;

// /* A pointer to the window and its size */
// typedef struct	s_window {
// 	void		*reference;
// 	t_vector	size;
// }				t_window;

// /* The 4 values that define a color */
// typedef struct	s_color {
// 	int	r;
// 	int	g;
// 	int	b;
// 	int	a;
// }				t_color;

// /* all info needed for an image */
// typedef struct	s_image {
// 	void		*reference;
// 	t_vector	size;
// 	char		*pixels;
// 	int			bits_per_pixel;
// 	int			line_size;
// 	int			endian;
// }				t_image;

// typedef struct	s_program {
// 	void		*mlx;
// 	t_window	window;
// 	t_image		sprite;
// 	t_vector	sprite_position;
// }				t_program;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_no_event(void *data);
int		handle_keypress(int keysym, t_data *data);



#endif
