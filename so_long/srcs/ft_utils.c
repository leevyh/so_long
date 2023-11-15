/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:37 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/14 15:20:07 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->xpm.img_player_right);
	mlx_destroy_image(game->mlx, game->xpm.img_player_left);
	mlx_destroy_image(game->mlx, game->xpm.img_path);
	mlx_destroy_image(game->mlx, game->xpm.img_wall);
	mlx_destroy_image(game->mlx, game->xpm.img_colect);
	mlx_destroy_image(game->mlx, game->xpm.img_exit_close);
	mlx_destroy_image(game->mlx, game->xpm.img_exit_open);
	mlx_destroy_image(game->mlx, game->img.img);
}

void	free_map(t_game *game)
{
	int	x;

	x = -1;
	if (game->map)
	{
		while (game->map[++x])
			free(game->map[x]);
		free(game->map[x]);
		free(game->map);
	}
}

int	close_window(t_game *game, int key)
{
	free_images(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game);
	if (key == A || key == LEFT || key == W || key == UP || key == S
		|| key == DOWN || key == D || key == RIGHT)
		ft_printf("GG WP !\n");
	else
		ft_printf("See you soon !\n");
	exit(0);
	return (0);
}

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
	free_map(game);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
