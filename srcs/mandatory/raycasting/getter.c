/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:55:59 by jewu              #+#    #+#             */
/*   Updated: 2025/01/10 17:22:24 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//get coordinates of intersection  point for
//vertical line (ray touches left or right side of tile)
//1: y_step/x_step = how much we are moving for each intersection point
//2: compute intersection point coordinates
//The size of hypotenuse is based on Pythagore's theorem: a² + b² = c²
//	therefore c = √a² + √b²
float	get_v_intersection(t_info *info, float angle)
{
	float	vert_x;
	float	vert_y;
	float	x_step;
	float	y_step;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	vert_x = floor((info->player->p_x / TILE_SIZE) * TILE_SIZE);
	vert_y = info->player->p_y + (vert_x - info->player->p_x) / tan(angle);
	return (sqrt(pow(vert_y, 2) + pow(vert_x, 2)));
}

//get coordinates of intersection point for
//horizontal line (ray touches top or bottom edge of tile)
//1: y_step/x_step = how much we are moving for each intersection point
//2: compute intersection point coordinates
//The size of hypotenuse is based on Pythagore's theorem: a² + b² = c²
//	therefore c = √a² + √b²
float	get_h_intersection(t_info *info, float angle)
{
	float	hori_x;
	float	hori_y;
	float	x_step;
	float	y_step;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	hori_y = floor((info->player->p_y / TILE_SIZE) * TILE_SIZE);
	hori_x = info->player->p_x + (hori_y - info->player->p_y) / tan(angle);
	return (sqrt(pow(hori_x, 2) + pow(hori_y, 2)));
}
