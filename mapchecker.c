/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:20:38 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/01 15:08:02 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A map is: a description file ending with the .ber
It has to be constructed with 3 components:
	-> walls, collectibles, and free space.

The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position

The map MUST:
• contain at least 1 exit, 1 collectible, and 1 starting position.
• be rectangular.
• be closed/surrounded by walls.

	Any misconfiguration: return("Error: explicit error message\n");
*/

#include "so_long.h"

/* 1. On check le nb d'arguments, le nom de la map, le fichier map */
void	check_filename(int argc, char *mapfile, t_game *game)
{
	int	fd;

	if (argc != 2)
		error_message("Not the good amount of arguments.\n", game);
	if (ft_strncmp(".ber", &mapfile[ft_strlen(mapfile) - 4], ft_strlen(mapfile))
		!= 0 || ft_strlen(mapfile) <= 4 || (ft_strnstr(mapfile, "/.ber",
				ft_strlen(mapfile)) != NULL))
		error_message("Wrong map name.\n", game);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		error_message("Wrong file.\n", game);
	close (fd);
}

/* 2. On compte le nombre de lignes pour creer le **tab */
void	linecount(char *mapfile, t_game *game)
{
	int		x;
	int		fd;
	char	c;

	fd = open(mapfile, O_RDONLY);
	x = 1;
	c = 0;
	while (x)
	{
		x = read(fd, &c, 1);
		if (x < 0)
			return ;
		if (x && c == '\n')
			game->height++;
	}
	close(fd);
	if (game->height <= 0)
		error_message("Empty map.\n", game);
}

/* 3. On cree la map */
void	create_map(char *mapfile, t_game *game)
{
	int		x;
	int		fd;
	char	*line;

	x = 0;
	linecount(mapfile, game);
	fd = open(mapfile, O_RDONLY);
	game->map = calloc(sizeof(char *), (game->height + 1));
	if (!game->map)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		game->map[x] = calloc(sizeof(char), ft_strlen(line));
		if (!game->map[x])
			error_message("Wrong malloc, map freed.\n", game);
		ft_strlcpy(game->map[x], line, ft_strlen(line));
		// printf("%s\n", game->map[x]);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	close(fd);
}

/* 4. On verifie la composition de la map */
void	check_map_elements(char **map, t_game *game)
{
	int	x;
	int	i;

	x = 0;
	while (map[++x])
	{
		i = 0;
		while (map[x][i] != '\0')
		{
			if (map[x][i] == 'C')
				game->colectible++;
			if (map[x][i] == 'E')
				game->exit++;
			if (map[x][i] == 'P')
			{
				game->p.x = i;
				game->p.y = x;
				game->start++;
			}
			i++;
		}
	}
	game->width = i;
	// printf("colectible: %d, start: %d, exit: %d\n", game->colectible, game->start, game->exit);
}

/* 5. On verifie les murs et le rectangle */
void	check_map_stucture(char **map, t_game *game)
{
	int	x;
	int	i;
	int	len;

	x = 0;
	check_map_elements(map, game);
	if (game->colectible <= 0 || game->exit != 1 || game->start != 1)
		error_message("Not the good amount of elements.\n", game);
	while (map[x])
	{
		i = 0;
		if (ft_strlen(map[x]) != game->width)
			error_message("Map isn't rectangle.\n", game);
		if (map[x][0] != '1' || map[x][game->width - 1] != '1')
			error_message("Map not surrounded by walls.\n", game);
		x++;
	}
	i = 0;
	while (map[0][i] && map[game->height - 1][i] && map[0][i] == '1'
		&& map[game->height - 1][i] == '1')
		i++;
	if (map[0][i] != '\0' || map[game->height - 1][i] != '\0')
		error_message("Map not surrounded by walls.\n", game);
}
