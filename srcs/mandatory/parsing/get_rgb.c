/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:56:52 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/15 15:08:33 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function that checks if the RGB value is already set
// -1 means that the value is not set
// Any other value means that the value is set
static int	rgb_already_set(int *rgb)
{
	if (rgb[0] != -1)
		return (FAILURE);
	if (rgb[1] != -1)
		return (FAILURE);
	if (rgb[2] != -1)
		return (FAILURE);
	return (SUCCESS);
}

// Function that gets the number from the line
// It will return the number and move the pointer to the next character
static int	get_number(char **line)
{
	int	num;

	num = 0;
	if (!line || !*line)
		return (-1);
	while (**line && ft_isspace(**line))
		(*line)++;
	if (!**line || !ft_isdigit(**line))
		return (-1);
	while (**line && ft_isdigit(**line))
	{
		num = num * 10 + (**line - '0');
		(*line)++;
	}
	while (**line && ft_isspace(**line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	return (num);
}

// Function that sets the RGB value
static int	set_rgb(int *rgb, int r, int g, int b)
{
	if (rgb_already_set(rgb) == FAILURE)
		return (error("Double RGB value detected"), FAILURE);
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
	return (SUCCESS);
}

// Function that gets the RGB value from the line
// Extracts the R, G, B values from the line with get_number
// Use set_rgb to set the RGB value in the info structure
int	get_rgb(t_info *info, char *line, int identifier)
{
	int	r;
	int	g;
	int	b;

	r = get_number(&line);
	g = get_number(&line);
	b = get_number(&line);
	if (r == -1 || g == -1 || b == -1)
		return (error("Missing / invalid RGB value"), 1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (error("Missing / invalid RGB value"), 1);
	if (identifier == F)
	{
		if (set_rgb(info->floor_rgb, r, g, b) != 0)
			return (FAILURE);
	}
	else if (identifier == C)
	{
		if (set_rgb(info->ceiling_rgb, r, g, b) != 0)
			return (FAILURE);
	}
	info->loaded_elements += 1;
	return (0);
}
