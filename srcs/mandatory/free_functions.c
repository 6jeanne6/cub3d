/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:10:40 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/02/02 17:11:21 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//free all images/textures
static void	free_img(t_info *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (info->textures[i]->mlx_img)
			mlx_destroy_image(info->mlx_ptr, info->textures[i]->mlx_img);
		free(info->textures[i]);
		i++;
	}
}

static void	free_map(t_info *info)
{
	int	i;

	i = 0;
	if (!info->map)
		return ;
	while (info->map[i] != NULL)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

void	free_info(t_info *info)
{
	if (!info)
		return ;
	free_img(info);
	if (info->img.mlx_img && info->parsing_succeed == SUCCESS)
		mlx_destroy_image(info->mlx_ptr, info->img.mlx_img);
	if (info->win_ptr && info->parsing_succeed == SUCCESS)
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	if (info->mlx_ptr)
		mlx_destroy_display(info->mlx_ptr);
	free(info->mlx_ptr);
	if (info->map)
		free_map(info);
	if (info->player)
		free(info->player);
	if (info->ray)
		free(info->ray);
	free(info);
}

int	close_and_exit(t_info *info)
{
	free_info(info);
	exit(0);
}

//free all structures
int	free_everything(t_info *info)
{
	free_info(info);
	return (1);
}
