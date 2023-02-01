/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:38:04 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/01 16:28:14 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	first_part(int argc, char **argv, t_game *game)
{
	set_on_null(game);
	check_filename(argc, argv[1], game);
	create_map(argv[1], game);
	check_map_stucture(game->map, game);
//	flood_fill(game);

	//error_message("Fin.\n", game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	
	first_part(argc, argv, &game);

/* Initialiser la mlx */
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (MLX_ERROR);

/* Creer une fenetre */
	game.win = mlx_new_window(game.mlx, game.width * SIZE_IMG, game.height * SIZE_IMG, "Leevyh's First Game");
	if (game.win == NULL)
	{
		free(game.win);
		return (MLX_ERROR);
	}

/* Creer une image */
	game.simg.img = mlx_new_image(game.mlx, game.width * SIZE_IMG, game.height * SIZE_IMG);
	game.simg.addr = mlx_get_data_addr(game.simg.img, &game.simg.bits_per_pixel, &game.simg.line_length,
		&game.simg.endian);

// Si la map est trop grande par rapport a l'ecran, message d'erreur

/* Afficher le jeu */
	load_images(&game);
	put_images(&game);
	// mlx_put_image_to_window(game.mlx, game.win, game.simg.img, 0, 0);

	mlx_loop_hook(game.mlx, &handle_no_event, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.win, ExitButton, 0, &close_window, &game);

	//mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

	mlx_loop(game.mlx);

	return (0);
}


