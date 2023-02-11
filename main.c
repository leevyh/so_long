/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:38:04 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/07 10:41:46 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	first_part(int argc, char **argv, t_game *game)
{
	game->map = 0;
	set_on_null(game);
	check_filename(argc, argv[1], game);
	create_map(argv[1], game);
	check_map_stucture(game->map, game);
	flood_fill(game);

	// error_message("Fin.\n", game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	first_part(argc, argv, &game);

	// if (game.width * SIZE_IMG > 2560 || game.height * SIZE_IMG > 1440)
	// 	error_message("Map too big.\n", &game);

/* Initialiser la mlx */
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);

/* Creer une fenetre */
	game.win = mlx_new_window(game.mlx, game.width * SIZE_IMG, game.height * SIZE_IMG, "Leevyh's First Game");
	if (game.win == NULL)
	{
		free(game.win);
		return (1);
	}

/* Creer une image */
	game.img.img = mlx_new_image(game.mlx, game.width * SIZE_IMG, game.height * SIZE_IMG);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length,
		&game.img.endian);

/* Afficher le jeu */
	load_images(&game);
	put_images(&game, RIGHT);				// FACE si autre perso

//	mlx_string_put(game.mlx, game.win, 1* SIZE_IMG, 1* SIZE_IMG, 0xFF0000, "Moves:");

	mlx_hook(game.win, KeyPress, 1L << 0, &key_map, &game);
	mlx_hook(game.win, EXIT, 0, &close_window, &game);

	mlx_loop_hook(game.mlx, put_images, &game);
	mlx_loop(game.mlx);

	return (0);
}


