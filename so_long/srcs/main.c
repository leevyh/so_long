/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:38:04 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/14 15:12:28 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A map is: a description file ending with the .ber
It has to be constructed with 3 components:
	-> walls, collectibles, and free space.

The map can be composed of only these 5 characters:
	0 for an empty space,
	1 for a wall,
	C for a collectible,
	E for a map exit,
	P for the player’s starting position

The map MUST:
• contain at least 1 exit, 1 collectible, and 1 starting position.
• be rectangular.
• be closed/surrounded by walls.

	Any misconfiguration: return("Error: explicit error message\n");
*/

#include "../so_long.h"

static void	first_part(int argc, char **argv, t_game *game)
{
	game->map = 0;
	set_on_null(game);
	check_filename(argc, argv[1], game);
	create_map(argv[1], game);
	check_map_stucture(game->map, game);
	flood_fill(game);
}

static void	ft_minilibx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return ;
	game->win = mlx_new_window(game->mlx, game->width * SIZE_IMG,
			game->height * SIZE_IMG, "Leevyh's First Game");
	if (game->win == NULL)
	{
		free(game->win);
		return ;
	}
	game->img.img = mlx_new_image(game->mlx, game->width * SIZE_IMG,
			game->height * SIZE_IMG);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	load_images(game);
	put_images(game, RIGHT);
	mlx_hook(game->win, KeyPress, 1L << 0, &key_map, game);
	mlx_hook(game->win, EXIT, 0, &close_window, game);
	mlx_loop_hook(game->mlx, put_images, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	first_part(argc, argv, &game);
	ft_minilibx(&game);
	return (0);
}
