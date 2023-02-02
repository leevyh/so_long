/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:37:19 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/02 14:12:37 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_on_null(t_game *game)
{
	game->colectible = 0;
	game->exit = 0;
	game->start = 0;
	game->width = 0;
	game->height = 0;
	game->moves = 0;
	game->end_game = 0;
}

void	error_message(char *str, t_game *game)
{
	int	x;

	x = 0;
	if (game->map)
	{
		while (game->map[x])
		{
			free(game->map[x]);
			x++;
		}
		free(game->map[x]);
		free(game->map);
	}
	ft_printf("Error: %s", str);
	exit(EXIT_FAILURE);
}
