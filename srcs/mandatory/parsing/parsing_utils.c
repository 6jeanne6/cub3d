/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:55:45 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/06 18:03:26 by lnjoh-tc         ###   ########.fr       */
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

// Function to check if 
bool	is_map_line(char *line, t_info *info)
{
	int	i;

	i = 0;
	if (info->loaded_elements == 6)
	{
		while (line[i] != '\0')
		{
			if ((line[i] == '1' || line[i] == '0'))
				return (true);
			i++;
		}
	}
	return (false);
}
