/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:55:45 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/08 02:45:55 by lnjoh-tc         ###   ########.fr       */
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
// Function that checks if the file is a .cub extension
int	map_is_cub(char *argv)
{
	int	len;
	int	i;

	len = ft_strlen(argv);
	i = 0;
	if (len < 4)
		return (FAILURE);
	while (argv[i] != '.')
		i++;
	if (ft_strncmp(argv + len, ".cub", 4) == 0
		|| ft_strncmp(argv + i, ".cub", len - i) == 0)
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
