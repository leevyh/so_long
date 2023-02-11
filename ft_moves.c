/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:43:58 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/07 10:28:23 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int col, int line, int key);
static int	move_checker(t_game *game, int col, int line, int key);

int	key_map(int key, t_game *game)
{
	int	line;
	int	col;

	line = game->p_perso.y;
	col = game->p_perso.x;
	if (key == ESC)
		close_window(game);
	else if (key == A || key == LEFT)
		col--;
	else if (key == W || key == UP)
		line--;
	else if (key == S || key == DOWN)
		line++;
	else if (key == D || key == RIGHT)
		col++;
	if (game->end_game == 0)
		move_player(game, col, line, key);
	return (0);
}

static void	move_player(t_game *game, int col, int line, int key)
{
	int	validate;

	validate = move_checker(game, col, line, key);
	if (validate > 0)
	{
		game->moves++;
		game->map[game->p_perso.y][game->p_perso.x] = '0';
		game->map[line][col] = 'P';
		game->p_perso.y = line;
		game->p_perso.x = col;
		put_images(game, key);
		printf("moves: %d\n", game->moves);
		if (validate == 2)
			close_window(game);
	}
}

static int	move_checker(t_game *game, int col, int line, int key)
{
	if (game->map[line][col] == '1')
		return (-1);
	if (game->map[line][col] == 'C')
		game->colectible--;
	if (game->map[line][col] == 'E' && game->colectible > 0)
		return (-1);
	if (game->map[line][col] == 'E' && game->colectible == 0)
	{
		game->map[game->p_perso.y][game->p_perso.x] = '0';
		game->end_game = 1;
		return (2);
	}
	if (key == A || key == W || key == S || key == D || key == UP
		|| key == DOWN || key == LEFT || key == RIGHT)
		return (1);
	else
		return (-1);
}
