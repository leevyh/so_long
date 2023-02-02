/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapplayability.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:08:30 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/02 16:22:59 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Fonction qui duplique la map et trouve le point de depart
pour ensuite ouvrir le robinet et remplir d'eau chaque chemin possible
si a la fin il reste un Exit et/ou des Collectibles c'est que le chemin
n'est pas faisable */

static void	mapcpy(t_game *cpy, t_game *game)
{
	int	y;

	y = 0;
	cpy->map = ft_calloc(sizeof(char *), (game->height + 1));
	if (!cpy->map)
		return ;
	while (game->map[y])
	{
		cpy->map[y] = ft_calloc(sizeof(char), ft_strlen(game->map[y]));
		if (!cpy->map[y])
		{
			free_map(cpy);
			error_message("Wrong malloc, map freed.\n", game);
		}
		ft_strlcpy(cpy->map[y], game->map[y], ft_strlen(game->map[y]));
		y++;
	}
}

static void	fill(char **map, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (map[cur.y][cur.x] == '0' || map[cur.y][cur.x] == 'P'
		|| map[cur.y][cur.x] == 'E' || map[cur.y][cur.x] == 'C')
	{
		map[cur.y][cur.x] = 'W';
		fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
		fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
		fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
		fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
	}
}

void	flood_fill(t_game *game)
{
	t_game	gamecpy;
	t_point	size;
	t_point	begin;

	mapcpy(&gamecpy, game);
	size.x = game->width;
	size.y = game->height;
	begin.x = game->p_perso.x;
	begin.y = game->p_perso.y;
	// for (int y = 0; y < size.y; ++y)
	// 	printf("%s\n", gamecpy.map[y]);
	// printf("\n");
	fill(gamecpy.map, size, begin, gamecpy.map[begin.y][begin.x]);
	// for (int y = 0; y < size.y; ++y)
	// 	printf("%s\n", gamecpy.map[y]);
	set_on_null(&gamecpy);
	check_map_elements(gamecpy.map, &gamecpy);
	if (gamecpy.colectible > 0 || gamecpy.exit > 0 || gamecpy.start > 0)
		error_message("Map unplayable.\n", game);
	free_map(&gamecpy);
}
