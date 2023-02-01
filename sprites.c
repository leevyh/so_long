/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:50:33 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/01 15:37:14 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_map(t_game *data, int line, int col);
static void	put_player(t_game *data, int line, int col);

void	load_images(t_game *data)
{
	// data->xpm.img_player_front = mlx_xpm_file_to_image(data->mlx, PLAYER_FRONT, &(data->width), &(data->height));
	// data->xpm.img_player_back = mlx_xpm_file_to_image(data->mlx, PLAYER_BACK, &(data->width), &(data->height));
	data->xpm.img_player_right = mlx_xpm_file_to_image(data->mlx, PLAYER_RIGHT, &(data->width), &(data->height));
	data->xpm.img_player_left = mlx_xpm_file_to_image(data->mlx, PLAYER_LEFT, &(data->width), &(data->height));
	data->xpm.img_exit_open = mlx_xpm_file_to_image(data->mlx, EXIT_OPEN, &(data->width), &(data->height));
	data->xpm.img_exit_close = mlx_xpm_file_to_image(data->mlx, EXIT_CLOSE, &(data->width), &(data->height));
	data->xpm.img_path = mlx_xpm_file_to_image(data->mlx, PATH, &(data->width), &(data->height));
	data->xpm.img_colect = mlx_xpm_file_to_image(data->mlx, COLECT, &(data->width), &(data->height));
	data->xpm.img_wall = mlx_xpm_file_to_image(data->mlx, WALL, &(data->width), &(data->height));
}

int	put_images(t_game *data)
{
	int	line;
	int	col;

	line = 0;
	while (data->map[line])
	{
		col = 0;
		while (data->map[line][col])
		{
			if (data->map[line][col] == '1' || data->map[line][col] == '0'
				|| data->map[line][col] == 'C' || data->map[line][col] == 'E')
				put_map(data, line, col);
			if (data->map[line][col] == 'P')
				put_player(data, line, col);
			col++;
		}
		line++;
	}
	return (1);
}

static void	put_map(t_game *data, int line, int col)
{
	if (data->map[line][col] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->xpm.img_wall, col * SIZE_IMG, line * SIZE_IMG);
	if (data->map[line][col] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->xpm.img_path, col * SIZE_IMG, line * SIZE_IMG);
	if (data->map[line][col] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->xpm.img_colect, col * SIZE_IMG, line * SIZE_IMG);


	if (data->map[line][col] == 'E')
	{
		if (data->colectible == 0)
			mlx_put_image_to_window(data->mlx, data->win,
				data->xpm.img_exit_open, col * SIZE_IMG, line * SIZE_IMG);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->xpm.img_exit_close, col * SIZE_IMG, line * SIZE_IMG);
	}
}

static void	put_player(t_game *data, int line, int col)
{
	if (data->map[line][col] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->xpm.img_player_left, col * SIZE_IMG, line * SIZE_IMG);
}
