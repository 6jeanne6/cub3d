/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:55:45 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/02/03 14:31:53 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function that check if the character is a space
int	ft_isspace(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v')
		|| (c == '\f') || (c == ' '))
		return (1);
	return (0);
}

// Function that checks if the file is a .cub extension
int	map_is_cub(char *argv)
{
	int	len;

	if (!argv)
		return (FAILURE);
	len = ft_strlen(argv);
	if (len < 5)
		return (FAILURE);
	if (ft_strncmp(argv + len - 4, ".cub", 4) == 0)
		return (SUCCESS);
	return (FAILURE);
}

bool	is_map_line(char *line, t_info *info, int *return_value)
{
	int	i;

	i = 0;
	if (info->loaded_elements == 6)
	{
		while (line[i] != '\0')
		{
			if (line[i] != 'N' && line[i] != 'S' && line[i] != 'N'
				&& line[i] != 'W' && line[i] != 'E' && line[i] != '0'
				&& line[i] != '1' && !ft_isspace(line[i]))
			{
				error("Invalid character detected in file\n"
					"Please be sure that the map is correctly formatted\n");
				*return_value = FAILURE;
				return (false);
			}
			i++;
		}
	}
	return (true);
}

// Function to get the player 2D position
void	get_player_position(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i] != NULL)
	{
		j = 0;
		while (info->map[i][j] != '\0')
		{
			if (info->map[i][j] == 'N' || info->map[i][j] == 'S'
				|| info->map[i][j] == 'E' || info->map[i][j] == 'W')
			{
				info->map_px = j;
				info->map_py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
