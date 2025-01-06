/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:55:26 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/06 18:16:35 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_isspace(map[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

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
				return (false);
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
		return (error("Invalid characters/spaces detected in map"), 1);
	if (check_doublons(info->map) == false)
		return (error("There are issues with the player in the map.\n"
				"Ensure there is exactly one player.\n"), 1);
	if (check_spaces(info->map) == false)
		return (error("Spaces found in the map"), 1);
	if (check_borders(info->map, info->height) == false)
		return (error("Invalid map borders"), 1);
	return (SUCCESS);
}
