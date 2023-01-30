/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:38:04 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/01/30 14:01:26 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	// set_on_null(&game);
	// check_filename(argc, argv[1], &game);
	// create_map(argv[1], &game);
	// check_map_stucture(game.map, &game);
	// flood_fill(&game);

	mlxpart(&game);



//	error_message("Fin.\n", &game);
	return (0);
}
