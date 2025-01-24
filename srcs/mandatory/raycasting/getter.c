/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:30:38 by jewu              #+#    #+#             */
/*   Updated: 2025/01/24 14:18:21 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//get the x_gap to know where to display pixel and
//how to display a portion of the texture onto the wall
float	get_x_gap(t_info *info, t_image *texture)
{
	float	x_gap;

	if (info->ray->horizontal_flag == 0)
		x_gap = fmodf(info->ray->vertical_y * (texture->width / TILE_SIZE),
				TILE_SIZE);
	else
		x_gap = fmodf(info->ray->horizontal_x * (texture->width / TILE_SIZE),
				TILE_SIZE);
	return (x_gap);
}

//get texture of the wall according to the angle of the ray
t_image	*get_wall_texture_rendering(t_info *info, int hori_flag)
{
	info->ray->ray_angle = normal_angle(info->ray->ray_angle);
	if (hori_flag == 0)
	{
		if (info->ray->ray_angle > PI / 2 && info->ray->ray_angle < 3 * PI / 2)
			return (which_cardinal_direction(info, WE));
		else
			return (which_cardinal_direction(info, EA));
	}
	else
	{
		if (info->ray->ray_angle > 0 && info->ray->ray_angle < PI)
			return (which_cardinal_direction(info, SO));
		else
			return (which_cardinal_direction(info, NO));
	}
	return (NULL);
}

//get coordinates of intersection  point for
//vertical line (ray touches left or right side of tile)
//1: y_step/x_step = how much we are moving for each intersection point
//2: compute intersection point coordinates
//3: reverse coordinates and steps according to direction
//4: the size of hypotenuse is based on Pythagore's theorem: a² + b² = c²
//	therefore c = √a² + √b²
float	get_v_line_intersection(t_info *info, float angle)
{
	float	vert_x;
	float	vert_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	vert_x = floor((info->player->p_x / TILE_SIZE) * TILE_SIZE);
	pixel = check_intersection(info->ray->ray_angle, &vert_x, &x_step, false);
	vert_y = info->player->p_y + (vert_x - info->player->p_x) / tan(angle);
	if ((is_right_zone(info->ray->ray_angle, 'x') && y_step < 0)
		|| (!is_right_zone(info->ray->ray_angle, 'x') && y_step > 0))
		y_step *= -1;
	while (hit_the_wall(info, vert_x, vert_y - pixel))
	{
		vert_x += x_step;
		vert_y += y_step;
	}
	info->ray->vertical_x = vert_x;
	info->ray->vertical_y = vert_y;
	return (sqrt(pow(vert_y, 2) + pow(vert_x, 2)));
}

//get coordinates of intersection point for
//horizontal line (ray touches top or bottom edge of tile)
//1: y_step/x_step = how much we are moving for each intersection point
//2: compute intersection point coordinates
//3: reverse coordinates and steps according to direction
//4: the size of hypotenuse is based on Pythagore's theorem: a² + b² = c²
//	therefore c = √a² + √b²
float	get_h_line_intersection(t_info *info, float angle)
{
	float	hori_x;
	float	hori_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	hori_y = floor((info->player->p_y / TILE_SIZE) * TILE_SIZE);
	pixel = check_intersection(info->ray->ray_angle, &hori_y, &y_step, true);
	hori_x = info->player->p_x + (hori_y - info->player->p_y) / tan(angle);
	if ((is_right_zone(info->ray->ray_angle, 'y') && x_step > 0)
		|| (!is_right_zone(info->ray->ray_angle, 'y') && x_step < 0))
		x_step *= -1;
	while (hit_the_wall(info, hori_x, hori_y - pixel))
	{
		hori_x += x_step;
		hori_y += y_step;
	}
	info->ray->horizontal_x = hori_x;
	info->ray->horizontal_y = hori_y;
	return (sqrt(pow(hori_x, 2) + pow(hori_y, 2)));
}
