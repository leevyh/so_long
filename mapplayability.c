/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapplayability.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:08:30 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/01 11:36:44 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Fonction qui duplique la map et trouve le point de depart
pour ensuite ouvrir le robinet et remplir d'eau chaque chemin possible
si a la fin il reste un Exit et/ou des Collectibles c'est que le chemin
n'est pas faisable */

void	fill(char **map, t_point size, t_point cur, char to_fill)
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
	int		y;

	y = 0;
	gamecpy = *game;
	size.x = gamecpy.width;
	size.y = gamecpy.height;
	begin.x = gamecpy.p.x;
	begin.y = gamecpy.p.y;
	// for (y = 0; y < size.y; ++y)
	// 	printf("%s\n", gamecpy.map[y]);
	// printf("\n");
	fill(gamecpy.map, size, begin, gamecpy.map[begin.y][begin.x]);
	// for (y = 0; y < size.y; ++y)
	// 	printf("%s\n", gamecpy.map[y]);
	set_on_null(&gamecpy);
	check_map_elements(gamecpy.map, &gamecpy);
	if (gamecpy.colectible > 0 || gamecpy.exit > 0 || gamecpy.start > 0)
		error_message("Map unplayable.\n", game);
}
