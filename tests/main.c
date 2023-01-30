/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:17:36 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/01/11 13:49:39 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_data	data;

/* Initialiser la mlx */
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);

/* Creer une fenetre */
	data.win = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Oh yeah!");
	if (data.win == NULL)
	{
		free(data.win);
		return (MLX_ERROR);
	}

/* Creer une image */
	data.simg.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.simg.addr = mlx_get_data_addr(data.simg.img, &data.simg.bits_per_pixel, &data.simg.line_length,
		&data.simg.endian);


	my_mlx_pixel_put(&data, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFF0000);
	mlx_put_image_to_window(data.mlx_ptr, data.win, data.simg.img, 0, 0);


	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	//mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

	mlx_loop(data.mlx_ptr);
}
