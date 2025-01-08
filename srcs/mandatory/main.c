/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:44 by jewu              #+#    #+#             */
/*   Updated: 2025/01/08 16:47:12 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int key, t_info *info)
{
	if (key == XK_Escape)
		close_and_exit(info);
	if (key == XK_a || key == XK_Left)
		info->player->x -= 10;
	if (key == XK_d || key == XK_Right)
		info->player->x += 10;
	if (key == XK_w || key == XK_Up)
		info->player->y -= 10;
	if (key == XK_s || key == XK_Down)
		info->player->y += 10;
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	draw_minimap(info, info->player);
	draw_player(info, info->player);
	return (0);
}

static void	hook(t_info *info)
{
	mlx_hook(info->win_ptr, KeyPress, KeyPressMask,
		&handle_keypress, info);
	mlx_hook(info->win_ptr, DestroyNotify, StructureNotifyMask,
		&close_and_exit, info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (error("Invalid number of arguments"), 1);
	info = init_info();
	if (!info)
		return (1);
	info->parsing_succeed = 0;
	if (parsing(info, argv) == FAILURE)
	{
		info->parsing_succeed = 1;
		print_info(info);
		return (free_info(info), 1);
	}
	print_info(info);
	if (init_everything(info, info->player) == 1)
		return (free_everything(info), 1);
	draw_minimap(info, info->player);
	draw_player(info, info->player);
	hook(info);
	mlx_loop(info->mlx_ptr);
	return (SUCCESS);
}
