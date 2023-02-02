/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:50:33 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/02 12:43:59 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_map(t_game *game, int line, int col);
static void	put_player(t_game *game, int line, int col);

void	load_images(t_game *game)
{
	// data->xpm.img_player_front = mlx_xpm_file_to_image(data->mlx, PLAYER_FRONT, &(data->width), &(data->height));
	// data->xpm.img_player_back = mlx_xpm_file_to_image(data->mlx, PLAYER_BACK, &(data->width), &(data->height));
	// game->xpm.img_player_right = mlx_xpm_file_to_image(game->mlx, PLAYER_RIGHT, &(game->width), &(game->height));
	game->xpm.img_player_left = mlx_xpm_file_to_image(game->mlx, PLAYER_LEFT, &(game->width), &(game->height));
	game->xpm.img_exit_open = mlx_xpm_file_to_image(game->mlx, EXIT_OPEN, &(game->width), &(game->height));
	game->xpm.img_exit_close = mlx_xpm_file_to_image(game->mlx, EXIT_CLOSE, &(game->width), &(game->height));
	game->xpm.img_path = mlx_xpm_file_to_image(game->mlx, PATH, &(game->width), &(game->height));
	game->xpm.img_colect = mlx_xpm_file_to_image(game->mlx, COLECT, &(game->width), &(game->height));
	game->xpm.img_wall = mlx_xpm_file_to_image(game->mlx, WALL, &(game->width), &(game->height));
}

int	put_images(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == '1' || game->map[line][col] == '0'
				|| game->map[line][col] == 'C' || game->map[line][col] == 'E')
				put_map(game, line, col);
			if (game->map[line][col] == 'P')
				put_player(game, line, col);
			col++;
		}
		line++;
	}
	return (1);
}

static void	put_map(t_game *game, int line, int col)
{
	if (game->map[line][col] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->xpm.img_wall, col * SIZE_IMG, line * SIZE_IMG);
	if (game->map[line][col] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->xpm.img_path, col * SIZE_IMG, line * SIZE_IMG);
	if (game->map[line][col] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->xpm.img_colect, col * SIZE_IMG, line * SIZE_IMG);
	if (game->map[line][col] == 'E')
	{
		if (game->colectible == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->xpm.img_exit_open, col * SIZE_IMG, line * SIZE_IMG);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->xpm.img_exit_close, col * SIZE_IMG, line * SIZE_IMG);
	}
}

static void	put_player(t_game *game, int line, int col)
{
	if (game->map[line][col] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->xpm.img_player_left, col * SIZE_IMG, line * SIZE_IMG);
}
