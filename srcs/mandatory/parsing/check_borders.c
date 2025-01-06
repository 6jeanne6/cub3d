/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:41:09 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/06 17:45:05 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_first_line(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

static bool	check_last_line(char **map, int height)
{
	int	j;

	j = 0;
	while (map[height - 1][j] != '\0')
	{
		if (map[height - 1][j] != '1')
			return (false);
		j++;
	}
	return (true);
}

static bool	check_columns(char **map, int height)
{
	int	i;
	int	width;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1')
			return (false);
		width = strlen(map[i]);
		if (map[i][width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_borders(char **map, int height)
{
	if (check_first_line(map) == false)
	{
		printf("Error: First line is not properly closed.\n");
		return (false);
	}
	if (check_last_line(map, height) == false)
	{
		printf("Error: Last line is not properly closed.\n");
		return (false);
	}
	if (check_columns(map, height) == false)
	{
		printf("Error: Columns are not properly closed.\n");
		return (false);
	}
	return (true);
}
