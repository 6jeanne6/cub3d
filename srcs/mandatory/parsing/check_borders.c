/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:41:09 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/08 02:47:19 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to get the maximum width of the map
static int	get_max_width(char **map, int height)
{
	int	width;
	int	i;
	int	len;

	width = 0;
	i = 0;
	while (i < height)
	{
		len = 0;
		while (map[i][len] != '\0')
			len++;
		if (len > width)
			width = len;
		i++;
	}
	return (width);
}

// Function to check the cells
static bool	check_cells(t_map_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == '0' && !info->visited[i][j])
			{
				if (!flood_fill(info, i, j))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

// Function to check if the region is surrounded by 1s
static bool	is_surrounded_by_ones(t_map_info *info)
{
	info->width = get_max_width(info->map, info->height);
	init_visited(info);
	if (!check_cells(info))
	{
		free_visited(info);
		return (false);
	}
	free_visited(info);
	return (true);
}

bool	check_borders(char **map, int height)
{
	t_map_info	info;

	info.map = map;
	info.height = height;
	if (!is_surrounded_by_ones(&info))
		return (false);
	return (true);
}
