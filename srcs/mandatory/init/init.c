/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:08:26 by jewu              #+#    #+#             */
/*   Updated: 2025/01/10 17:27:19 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_player(t_info *info, t_player *player)
{
	player->p_x = info->map_px * TILE_SIZE + TILE_SIZE / 2;
	player->p_y = info->map_py * TILE_SIZE + TILE_SIZE / 2;
	player->angle = PI;
	player->fov = (FOV * PI) / 180;
	return (0);
}

static int	init_window(t_info *info)
{
	info->width = WIDTH;
	info->height = HEIGHT;
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			info->width, info->height, "CUB3D");
	if (!info->win_ptr)
		return (error("Error of win ptr\n"), 1);
	return (0);
}

int	init_everything(t_info *info)
{
	if (init_window(info) == 1)
		return (1);
	info->map_px = 3;
	info->map_py = 10;
	return (0);
}
