/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:37 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/01/30 13:44:21 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function needs to exist, but it is useless for the moment */
int	handle_no_event(void *data)
{
	return (0);
}

/* Gerer les touches enfoncees */
int	handle_keypress(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
		{
			mlx_destroy_window(data->mlx, data->win);
			mlx_destroy_image(data->mlx, data->simg.img);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			exit (0);
		}

	printf("Keypress: %d\n", keysym);
	return (0);
}
