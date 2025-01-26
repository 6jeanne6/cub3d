/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:40:58 by jewu              #+#    #+#             */
/*   Updated: 2025/01/26 21:40:24 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//raycasting
//1: initialize ray angle at left of FOV \ PLAYER /
//2: cast a rayon to fill screen width <---------->
//3: get size of hypotenuse by getting
// 		- horizontal intersection (top/bottom edge of tile) point
// 		- vertical intersection (left/right edge of tile) point
//4: wall rendering
//5: continue with next ray by incrementing its angle
void	raycasting(t_info *info, t_ray *ray)
{
	int		rayon;
	double	h_inter;
	double	v_inter;

	rayon = 0;
	ray->ray_angle = info->player->angle - (info->player->fov / 2);
	while (rayon < WIDTH)
	{
		ray->horizontal_flag = 0;
		h_inter = get_h_line_intersection(info, normal_angle(ray->ray_angle));
		v_inter = get_v_line_intersection(info, normal_angle(ray->ray_angle));
		if (h_inter >= v_inter)
			ray->distance = v_inter;
		else
		{
			ray->distance = h_inter;
			ray->horizontal_flag = 1;
		}
		wall_rendering(info, rayon);
		rayon++;
		ray->ray_angle += info->player->fov / WIDTH;
	}
}
