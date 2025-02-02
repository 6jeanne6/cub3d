/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:39:50 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/02/02 17:06:12 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//initialize image to manipulate pixels
void	init_img(t_info *info)
{
	info->img.mlx_img = mlx_new_image(info->mlx_ptr, WIDTH, HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.mlx_img,
			&info->img.bits_per_pixel, &info->img.size_line, &info->img.endian);
	info->img.tile_size = TILE_SIZE;
	info->img.width = info->cols;
	info->img.height = info->rows;
}

//initialize window
int	init_window(t_info *info)
{
	info->win_ptr = mlx_new_window(info->mlx_ptr, WIDTH, HEIGHT, "GET CUB3D");
	if (!info->win_ptr)
		return (error("Error of win ptr\n"), 1);
	init_img(info);
	return (0);
}

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
		info->textures[i]->id = -1;
		i++;
	}
	info->parsing_succeed = SUCCESS;
	return (1);
}

static int	alloc_structures(t_info *info)
{
	info->player = ft_calloc(1, sizeof(t_player));
	if (!info->player)
		return (free_info(info), 1);
	info->ray = ft_calloc(1, sizeof(t_ray));
	if (!info->ray)
		return (free_info(info), 1);
	return (0);
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
	info->rows = 0;
	info->cols = 0;
	info->map = NULL;
	info->loaded_elements = 0;
	if (alloc_structures(info) == 1)
		return (error("Error of alloc"), NULL);
	return (info);
}
