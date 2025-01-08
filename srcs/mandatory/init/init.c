/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:08:26 by jewu              #+#    #+#             */
/*   Updated: 2025/01/08 16:32:13 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_player(t_player *player)
{
	player->x = WIDTH / 2 - 50 / 2;
	player->y = HEIGHT / 2 - 50 / 2;
	return (0);
}

static int	init_window(t_info *info)
{
	info->width = WIDTH;
	info->height = HEIGHT;
	info->win_ptr = mlx_new_window(info->mlx_ptr, info->width, info->height,
			"CUB3D");
	if (!info->win_ptr)
		return (error("Error of win ptr\n"), 1);
	return (0);
}

int	init_everything(t_info *info, t_player *player)
{
	if (init_window(info) == 1)
		return (1);
	if (init_player(player) == 1)
		return (1);
	return (0);
}
