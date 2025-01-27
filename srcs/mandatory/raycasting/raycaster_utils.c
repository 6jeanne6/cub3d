/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:33:16 by jewu              #+#    #+#             */
/*   Updated: 2025/01/27 17:42:57 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//the rayon touches the wall or not
//check if we are not accessing outside of map
// wall_x & wall_y = point position in 3D space in TILE
int	hit_the_wall(t_info *info, float x, float y)
{
	int	wall_x;
	int	wall_y;

	if (x < 0 || y < 0)
		return (0);
	wall_x = floor(x / TILE_SIZE);
	wall_y = floor(y / TILE_SIZE);
	if (wall_x >= info->cols || wall_y >= info->rows)
		return (0);
	if (info->map[wall_y] && wall_x <= (int)ft_strlen(info->map[wall_y]))
		if (info->map[wall_y][wall_x] == '1')
			return (0);
	return (1);
}

// 0 - π = right - left
// π/2 - 3π/2 = up - down  
int	is_right_zone(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > PI / 2 && angle < 3 * PI / 2)
			return (1);
	}
	return (0);
}

//Cut trigonometric cirle in two:
// 0 - π = upper half
// π - 2π = lower half
// WARNING: we are in a graphical plan, so y axis increases downwards
int	check_intersection(double angle, float *inter, float *step, bool is_h)
{
	if (is_h)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

//to remain in 0-2π field(trigonometric circle)
double	normal_angle(double angle)
{
	if (angle < 0)
		angle += 2 * PI;
	else if (angle > (2 * PI))
		angle -= 2 * PI;
	return (angle);
}
