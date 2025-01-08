/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:02:16 by jewu              #+#    #+#             */
/*   Updated: 2025/01/08 16:45:39 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//draw 1 tile
static void	draw_tile(t_info *info, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
			mlx_pixel_put(info->mlx_ptr, info->win_ptr, x + i, y + j, color);
	}
}

//draw 2D map
void	draw_minimap(t_info *info, t_player *player)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = -1;
	x = 0;
	y = 0;
	(void)player;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (info->map[i][j] == '1')
				draw_tile(info, x, y, 0xFFFF00);
			else if (info->map[i][j] == '0')
				draw_tile(info, x, y, 0x808080);
		}
	}
}

//draw a square to represent the player
void	draw_player(t_info *info, t_player *player)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
			mlx_pixel_put(info->mlx_ptr, info->win_ptr, player->x + i,
				player->y + j, 0xFF0000);
	}
}
