/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr >                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:38:38 by jewu              #+#    #+#             */
/*   Updated: 2025/01/23 17:38:38 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//the fov rotates, normalize angle in trigonometric field
void	the_player_rotates(t_info *info, int right)
{
	if (right == 1)
	{
		info->player->angle += ROT_SPEED;
		if (info->player->angle > 2 * PI)
			info->player->angle -= 2 * PI;
	}
	else
	{
		info->player->angle -= ROT_SPEED;
		if (info->player->angle < 0)
			info->player->angle += 2 * PI;
	}
}

//player moves in a direction
void	the_player_moves(t_info *info, double x_move, double y_move)
{
	int	new_px;
	int	new_py;
	int	on_map_x;
	int	on_map_y;

	new_px = roundf(info->player->p_x + x_move);
	new_py = round(info->player->p_y + y_move);
	on_map_x = new_px / TILE_SIZE;
	on_map_y = new_py / TILE_SIZE;
	info->player->p_x = new_px;
	info->player->p_y = new_py;
}

//move the player or the camera
void	i_can_move(t_info *info, double x_move, double y_move)
{
	if (info->rotation_left_right == ROTATE_LEFT)
		the_player_rotates(info, 0);
	if (info->rotation_left_right == ROTATE_RIGHT)
		the_player_rotates(info, 1);
	if (info->go_up_down == GO_UP)
	{
		x_move = cosf(info->player->angle) * PLAYER_SPEED;
		y_move = sinf(info->player->angle) * PLAYER_SPEED;
	}
	if (info->go_up_down == GO_DOWN)
	{
		x_move = -cosf(info->player->angle) * PLAYER_SPEED;
		y_move = -sinf(info->player->angle) * PLAYER_SPEED;
	}
	if (info->go_left_right == GO_LEFT)
	{
		x_move = sinf(info->player->angle) * PLAYER_SPEED;
		y_move = -cosf(info->player->angle) * PLAYER_SPEED;
	}
	if (info->go_left_right == GO_RIGHT)
	{
		x_move = -sinf(info->player->angle) * PLAYER_SPEED;
		y_move = cosf(info->player->angle) * PLAYER_SPEED;
	}
	the_player_moves(info, x_move, y_move);
}
