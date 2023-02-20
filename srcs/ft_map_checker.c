/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:20:38 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/02/20 12:13:37 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* 1. On check le nb d'arguments, le nom de la map, le fichier map */
void	check_filename(int argc, char *mapfile, t_game *game)
{
	int	fd;

	if (argc != 2)
		error_message("Error: Not the good amount of arguments.\n", game);
	if (ft_strncmp(".ber", &mapfile[ft_strlen(mapfile) - 4], ft_strlen(mapfile))
		!= 0 || ft_strlen(mapfile) <= 4 || (ft_strnstr(mapfile, "/.ber",
				ft_strlen(mapfile)) != 0))
	{
		ft_printf("Error: %s\n", strerror(EBADF));
		exit (EXIT_FAILURE);
	}
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: %s\n", strerror(ENOENT));
		exit (EXIT_FAILURE);
	}
	close (fd);
}

/* 2. On compte le nombre de lignes pour creer le **tab */
static void	linecount(char *mapfile, t_game *game)
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
		error_message("Error: Empty map.\n", game);
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
	game->map = ft_calloc(sizeof(char *), (game->height + 1));
	if (!game->map)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		game->map[x] = ft_calloc(sizeof(char), ft_strlen(line));
		if (!game->map[x])
			error_message("Error: Wrong malloc, map freed.\n", game);
		ft_strlcpy(game->map[x], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		x++;
	}
	close(fd);
}

/* 4. On verifie la composition de la map */
void	check_map_elements(char **map, t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				game->colectible++;
			if (map[y][x] == 'E')
				game->exit++;
			if (map[y][x] == 'P')
			{
				game->p_perso.x = x;
				game->p_perso.y = y;
				game->start++;
			}
		}
	}
	game->width = x;
}

/* 5. On verifie les murs et le rectangle */
void	check_map_stucture(char **map, t_game *game)
{
	int	x;
	int	i;

	x = -1;
	check_map_elements(map, game);
	if (game->colectible <= 0 || game->exit != 1 || game->start != 1)
		error_message("Error: Not the good amount of elements.\n", game);
	while (map[++x])
	{
		i = 0;
		if ((int)ft_strlen(map[x]) != game->width)
			error_message("Error: Map isn't rectangle.\n", game);
		if (map[x][0] != '1' || map[x][game->width - 1] != '1')
			error_message("Error: Map not surrounded by walls.\n", game);
	}
	i = 0;
	while (map[0][i] && map[game->height - 1][i] && map[0][i] == '1'
		&& map[game->height - 1][i] == '1')
		i++;
	if (map[0][i] != '\0' || map[game->height - 1][i] != '\0')
		error_message("Error: Map not surrounded by walls.\n", game);
}
