/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:55:26 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/08 02:50:47 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr(VALID_MAP_CHARS, map[i][j]))
			{
				if (map[i][j] != ' ')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static bool	check_doublons(char **map)
{
	int	i;
	int	j;
	int	pos;

	pos = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				pos++;
			j++;
		}
		i++;
	}
	if (pos > 1 || pos == 0)
		return (false);
	return (true);
}

int	parse_map(t_info *info)
{
	if (check_characters(info->map) == false)
		return (error("Invalid characters detected in map"), 1);
	if (check_doublons(info->map) == false)
		return (error("There are issues with the player in the map.\n"
				"Ensure there is exactly one player.\n"), 1);
	if (check_borders(info->map, info->height) == false)
		return (error("The map is not surrounded by walls\n"), 1);
	return (SUCCESS);
}
