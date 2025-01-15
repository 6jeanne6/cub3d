/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:12:57 by jewu              #+#    #+#             */
/*   Updated: 2025/01/15 16:59:57 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//put pixel with color at (x, y) coordinate
void	super_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	(void)info;
	(void)color;
	if (x < 0)
		return ;
	else if (x > WIDTH)
		return ;
	if (y < 0)
		return ;
	else if (y > HEIGHT)
		return ;
	//mlx_pixel_put(void);
}

//return texture of a cardinal direction
t_image	*which_cardinal_direction(t_info *info, char *direction)
{
	int	i;

	i = -1;
	while (info->textures[i])
	{
		if (!ft_strcmp(info->textures[i]->id, direction))
			return (info->textures[i]->mlx_img);
	}
	return (NULL);
}
