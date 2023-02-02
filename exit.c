/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:37 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/02 16:35:57 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_images(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	printf("GG WP !\n");
	exit(0);
	return (0);
}

void	free_images(t_game *game)
{
	// mlx_destroy_image(data->data->mlx_ptr, data->data->img_player_front);
	// mlx_destroy_image(data->data->mlx_ptr, data->data->img_player_back);
	mlx_destroy_image(game->mlx, game->xpm.img_player_left);
	// mlx_destroy_image(game->mlx, game->xpm.img_player_right);
	mlx_destroy_image(game->mlx, game->xpm.img_path);
	mlx_destroy_image(game->mlx, game->xpm.img_wall);
	mlx_destroy_image(game->mlx, game->xpm.img_colect);
	mlx_destroy_image(game->mlx, game->xpm.img_exit_close);
	mlx_destroy_image(game->mlx, game->xpm.img_exit_open);
}

void	free_map(t_game *game)
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
}
