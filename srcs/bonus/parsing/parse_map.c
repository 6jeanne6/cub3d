/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:55:26 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/02/03 15:05:29 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	line_with_only_whitespace(char *line)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (!ft_isspace(line[j]))
			return (false);
		j++;
	}
	return (true);
}

static bool	check_empty_line(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (false);
	while (map[i] != NULL)
	{
		if (map[i][0] == '\n' || line_with_only_whitespace(map[i]) == true)
			return (true);
		i++;
	}
	return (false);
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
				"Ensure there is exactly one player."), 1);
	if (check_empty_line(info->map) == true)
		return (error("Empty lines detected in map"), 1);
	if (check_borders(info, info->map) == 1)
		return (error("The map is not surrounded by walls"), 1);
	get_player_position(info);
	return (SUCCESS);
}
