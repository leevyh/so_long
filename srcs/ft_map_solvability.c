/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_solvability.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:08:30 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/14 13:52:44 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* 6.1. On copie la map */
static void	mapcpy(t_game *cpy, t_game *game)
{
	int	y;

	y = -1;
	cpy->map = ft_calloc(sizeof(char *), (game->height + 1));
	if (!cpy->map)
		return ;
	while (game->map[++y])
	{
		cpy->map[y] = ft_strdup(game->map[y]);
		if (!cpy->map[y])
		{
			free_map(cpy);
			error_message("Error: Wrong malloc, map freed.\n", game);
		}
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

/* 6.2. On se positionne sur la case depart et remplit
les cases d'eau (fonction fill) si apres avoir rempli
toutes les cases accessibles il reste la sortie et/ou
un collectible c'est que la map est impossible a terminer. */
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
	fill(gamecpy.map, size, begin, gamecpy.map[begin.y][begin.x]);
	set_on_null(&gamecpy);
	check_map_elements(gamecpy.map, &gamecpy);
	if (gamecpy.colectible > 0 || gamecpy.exit > 0 || gamecpy.start > 0)
	{
		free_map(&gamecpy);
		error_message("Error: Map unsolvable.\n", game);
	}
	free_map(&gamecpy);
}
