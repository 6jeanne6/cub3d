/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:44 by jewu              #+#    #+#             */
/*   Updated: 2025/01/15 15:57:02 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int key, t_info *info)
{
	if (key == XK_Escape)
		close_and_exit(info);
	if (key == XK_a)
		info->player->p_x -= 10;
	if (key == XK_d)
		info->player->p_x += 10;
	if (key == XK_w)
		info->player->p_y -= 10;
	if (key == XK_s)
		info->player->p_y += 10;
	// if (key == XK_Left)
	// 	rotate_left;
	// if (key == XK_Right)
	// 	rotate_right;
	return (0);
}

static void	hook(t_info *info)
{
	mlx_hook(info->win_ptr, KeyPress, KeyPressMask,
		&handle_keypress, info);
	mlx_hook(info->win_ptr, DestroyNotify, StructureNotifyMask,
		&close_and_exit, info);
}

static int	loop_the_game(void *param)
{
	t_info	*info;

	info = param;
	init_player(info, info->player);
	raycasting(info, info->ray);
	return (0);
}

static void	start_game(t_info *info)
{
	mlx_loop_hook(info->mlx_ptr, &loop_the_game, &info);
	mlx_loop(info->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (error("Invalid number of arguments"), 1);
	info = init_info();
	if (!info)
		return (1);
	if (parsing(info, argv) == FAILURE)
		return (free_info(info), 1);
	if (init_everything(info) == 1)
		return (free_everything(info), 1);
	// draw_minimap(info, info->player);
	// draw_player(info, info->player);
	hook(info);
	start_game(info);
	return (SUCCESS);
}
