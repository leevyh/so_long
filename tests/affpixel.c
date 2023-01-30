/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoletzk <lkoletzk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:47:09 by lkoletzk          #+#    #+#             */
/*   Updated: 2023/01/11 13:47:53 by lkoletzk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Afficher un pixel
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->simg.addr + (y * data->simg.line_length + x * (data->simg.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
