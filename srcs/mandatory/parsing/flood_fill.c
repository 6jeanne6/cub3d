/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:18:27 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/08 02:49:21 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to free visited map
void	free_visited(t_map_info *info)
{
	int	i;

	i = 0;
	while (i < info->height)
	{
		free(info->visited[i]);
		i++;
	}
	free(info->visited);
}

// Function to initialize visited map
void	init_visited(t_map_info *info)
{
	int	i;

	info->visited = malloc(info->height * sizeof(bool *));
	i = 0;
	while (i < info->height)
	{
		info->visited[i] = malloc(info->width * sizeof(bool));
		ft_memset(info->visited[i], 0, info->width * sizeof(bool));
		i++;
	}
}

// Flood fill function, traversing the map and marking visited cells
bool	flood_fill(t_map_info *info, int x, int y)
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	if (x < 0 || x >= info->height || y < 0 || y >= info->width)
		return (false);
	if (info->visited[x][y] || info->map[x][y] == '1')
		return (true);
	info->visited[x][y] = true;
	up = flood_fill(info, x - 1, y);
	down = flood_fill(info, x + 1, y);
	left = flood_fill(info, x, y - 1);
	right = flood_fill(info, x, y + 1);
	return (up && down && left && right);
}
