/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:39:50 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/08 13:11:12 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Initialize memory for textures
static int	init_textures(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		info->textures[i] = ft_calloc(1, sizeof(t_image));
		if (!info->textures[i])
		{
			error("ft_calloc failed");
			return (0);
		}
		i++;
	}
	return (1);
}

// Function that initialize the info struct
t_info	*init_info(void)
{
	t_info	*info;
	int		i;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (error("ft_calloc failed"), NULL);
	if (!init_textures(info))
		return (free_info(info), NULL);
	i = 0;
	while (i < 3)
	{
		info->floor_rgb[i] = -1;
		info->ceiling_rgb[i] = -1;
		i++;
	}
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		return (error("mlx_init failed"), free_info(info), NULL);
	info->player = ft_calloc(1, sizeof(t_player));
	if (!info->player)
		return (free_info(info), NULL);
	info->map = NULL;
	info->loaded_elements = 0;
	return (info);
}
