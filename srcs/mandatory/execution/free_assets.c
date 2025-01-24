/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:40:18 by jewu              #+#    #+#             */
/*   Updated: 2025/01/24 13:45:04 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//free textures
void	free_textures(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 4 && info->textures[i])
	{
		if (info->textures[i]->mlx_img)
		{
			mlx_destroy_image(info->mlx_ptr, info->textures[i]->mlx_img);
			free(info->textures[i]->mlx_img);
		}
		free(info->textures[i]);
	}
}
