/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr >                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:33:04 by jewu              #+#    #+#             */
/*   Updated: 2025/01/23 16:33:04 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	loop_the_game(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->img.mlx_img);
	init_img(info);
	i_can_move(info, 0, 0);
	raycasting(info, info->ray);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
		info->img.mlx_img, 0, 0);
	return (0);
}

//init which direction player should see with position in 3d map
//and player FOV
static void	init_vision(t_info *info)
{
	char	c;

	c = info->map[info->map_py][info->map_px];
	if (c == 'E')
		info->player->angle = 0;
	if (c == 'S')
		info->player->angle = PI / 2;
	if (c == 'W')
		info->player->angle = PI;
	if (c == 'N')
		info->player->angle = 3 * PI / 2;
	info->player->p_x = (info->map_px * TILE_SIZE) + TILE_SIZE / 2;
	info->player->p_y = (info->map_py * TILE_SIZE) + TILE_SIZE / 2;
	info->player->fov = (float)FOV * (PI / 180);
}

//launch the game
void	lets_execute_the_game(t_info *info)
{
	init_vision(info);
	keyboard_hook(info);
	mlx_hook(info->win_ptr, DestroyNotify, StructureNotifyMask,
		&close_and_exit, info);
	mlx_loop_hook(info->mlx_ptr, &loop_the_game, info);
	mlx_loop(info->mlx_ptr);
}
