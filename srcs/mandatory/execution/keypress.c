/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr >                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:43:10 by jewu              #+#    #+#             */
/*   Updated: 2025/01/23 16:43:10 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//reset flag when keyrelease
int    handle_keyrelease(int key, t_info *info)
{
    /*
    if (info->go_left_right == GO_LEFT || info->go_left_right == GO_RIGHT)
        info->go_left_right = 0;
    if (info->go_up_down == GO_UP || info->go_up_down == GO_DOWN)
        info->go_up_down = 0;
    if (info->rotation_left_right == ROTATE_LEFT
        || info->rotation_left_right == ROTATE_RIGHT)
        info->rotation_left_right = 0;
    */
    if (key == XK_a)
        info->go_left_right = 0;
    if (key == XK_d)
        info->go_left_right = 0;
    if (key == XK_w)
        info->go_up_down = 0;
    if (key == XK_s)
        info->go_up_down = 0;
    if (key == XK_Left)
        info->rotation_left_right = 0;
    if (key == XK_Right)
        info->rotation_left_right = 0;
    return (SUCCESS);
}

//set flag to a direction when keypress
int	handle_keypress(int key, t_info *info)
{
	if (key == XK_Escape)
		close_and_exit(info);
	if (key == XK_a)
		info->go_left_right = GO_LEFT;
	if (key == XK_d)
		info->go_left_right = GO_RIGHT;
	if (key == XK_w)
		info->go_up_down = GO_UP;
	if (key == XK_s)
		info->go_up_down = GO_DOWN;
	if (key == XK_Left)
		info->rotation_left_right = ROTATE_LEFT;
	if (key == XK_Right)
		info->rotation_left_right = ROTATE_RIGHT;
	return (SUCCESS);
}

void	keyboard_hook(t_info *info)
{
	printf("info in keyboard hook: %p\n", info);
	mlx_hook(info->win_ptr, KeyPress, KeyPressMask,
		&handle_keypress, info);
	mlx_hook(info->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		info);
}
