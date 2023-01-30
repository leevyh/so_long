/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:28:20 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/01/30 14:10:45 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlxpart(t_game *game)
{
/* Initialiser la mlx */
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (MLX_ERROR);

/* Creer une fenetre */
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "GAME NAME");
	if (game->win == NULL)
	{
		free(game->win);
		return (MLX_ERROR);
	}

/* Creer une image */
	game->simg.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->simg.addr = mlx_get_data_addr(game->simg.img, &game->simg.bits_per_pixel, &game->simg.line_length,
		&game->simg.endian);


	my_mlx_pixel_put(game, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 0xFF0000);
	mlx_put_image_to_window(game->mlx, game->win, game->simg.img, 0, 0);


	mlx_loop_hook(game->mlx, &handle_no_event, &game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, &game);
	//mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

	mlx_loop(game->mlx);
	return (0);
}
