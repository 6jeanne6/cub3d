/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:41:09 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/14 16:59:24 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to check if a cell is bordered by invalid cells
static int	is_bordered(char **map, int i, int j)
{
	if (i == 0 || j == 0)
		return (1);
	if (map[i + 1] == NULL || map[i - 1] == NULL
		|| map[i][j + 1] == '\0' || map[i][j - 1] == '\0'
		|| map[i - 1][j] == '\0' || map[i][j + 1] == 0
		|| map[i][j - 1] == 0)
		return (1);
	if (ft_isspace(map[i - 1][j]) || ft_isspace(map[i + 1][j])
		|| ft_isspace(map[i][j + 1]) || ft_isspace(map[i][j - 1])
		|| map[i - 1][j] == 0 || map[i + 1][j] == 0
		|| map[i][j - 1] == 0 || map[i][j + 1] == 0)
		return (1);
	return (0);
}

// Function to check if the map is surrounded by 1s
int	check_borders(t_info *info, char **map)
{
	size_t	max_cols;
	int		i;
	int		j;

	i = 0;
	max_cols = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (is_bordered(map, i, j))
					return (1);
			}
			if (ft_strlen(map[i]) > max_cols)
				max_cols = ft_strlen(map[i]);
			j++;
		}
		i++;
	}
	info->cols = max_cols;
	return (0);
}
