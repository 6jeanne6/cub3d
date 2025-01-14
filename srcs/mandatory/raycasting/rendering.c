/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:13:27 by jewu              #+#    #+#             */
/*   Updated: 2025/01/14 17:19:55 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//DRAW THE CEILING
static void	draw_the_ceiling(t_info *info, int rayon, double bottom_pixel,
double top_pixel)
{
	;
}

//DRAW THE FLOOR
static void	draw_the_floor(t_info *info, int rayon, double bottom_pixel,
double top_pixel)
{
	;
}

//DRAW THE WALL
//1: load the wall texture
//2: scale: 
static void	draw_the_wall(t_info *info, double wall_height, double bottom_pixel,
double top_pixel)
{
	t_image	*texture;
	double	x_o;
	double	y_o;
	double	scale;

	texture = get_wall_texture_rendering(info, info->ray->wall_flag);
	scale = (double)texture->height / wall_height;
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
