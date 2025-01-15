/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:13:27 by jewu              #+#    #+#             */
/*   Updated: 2025/01/15 17:01:58 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//DRAW THE CEILING
static void	draw_the_ceiling(t_info *info, int rayon, double bottom_pixel,
double top_pixel)
{
	(void)info;
	(void)rayon;
	(void)bottom_pixel;
	(void)top_pixel;
}

//DRAW THE FLOOR
static void	draw_the_floor(t_info *info, int rayon, double bottom_pixel,
double top_pixel)
{
	(void)info;
	(void)rayon;
	(void)bottom_pixel;
	(void)top_pixel;
}

//DRAW THE WALL
//1: load the wall texture
//2: scale
static void	draw_the_wall(t_info *info, double wall_height, double bottom_pixel,
double top_pixel)
{
	t_image	*texture;
	double	x_gap;
	double	y_gap;
	double	scale;

	texture = get_wall_texture_rendering(info, info->ray->horizontal_flag);
	scale = (double)texture->height / wall_height;
	x_gap = get_x_gap(info, texture);
	y_gap = (top_pixel - (HEIGHT / 2) + (wall_height / 2)) * scale;
	if (y_gap < 0)
		y_gap = 0;
	while (top_pixel < bottom_pixel)
	{
		//super_mlx_pixel_put();
		y_gap += scale;
		top_pixel++;
	}
}

//WALL RENDERING
//1: get the height of a wall
//2: get te bottom and top pixel of a wall
//3: draw the wall
//4: draw the floor and ceiling
void	wall_rendering(t_info *info, int rayon)
{
	double	wall_height;
	double	bottom_pixel;
	double	top_pixel;

	info->ray->distance *= cos(normal_angle(info->ray->ray_angle
				- info->player->angle));
	wall_height = (TILE_SIZE / info->ray->ray_angle) * ((WIDTH / 2)
			/ tan(info->player->fov / 2));
	bottom_pixel = (HEIGHT / 2) + (wall_height / 2);
	top_pixel = (HEIGHT / 2) - (wall_height / 2);
	if (bottom_pixel > WIDTH)
		bottom_pixel = 0;
	if (top_pixel < WIDTH)
		top_pixel = 0;
	info->ray->index = rayon;
	draw_the_wall(info, wall_height, bottom_pixel, top_pixel);
	draw_the_floor(info, rayon, bottom_pixel, top_pixel);
	draw_the_ceiling(info, rayon, bottom_pixel, top_pixel);
}
