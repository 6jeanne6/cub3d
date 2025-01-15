/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:20:53 by jewu              #+#    #+#             */
/*   Updated: 2025/01/15 16:22:58 by jewu             ###   ########.fr       */
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
	info->screen_width = WIDTH;
	info->screen_height = HEIGHT;
	info->win_ptr = mlx_new_window(info->mlx_ptr,
			info->screen_width, info->screen_height, "CUB3D");
	if (!info->win_ptr)
		return (error("Error of win ptr\n"), 1);
	return (0);
}

int	init_everything(t_info *info)
{
	if (init_window(info) == 1)
		return (1);
	return (0);
}
