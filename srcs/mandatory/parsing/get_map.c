/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:32:14 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/13 15:00:30 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to copy characters 
char	*copy_line_from_file(const char *s)
{
	int		j;
	char	*result;

	j = 0;
	result = NULL;
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (0);
	while (s[j] != '\0' && s[j] != '\n')
	{
		result[j] = s[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

// Function that loads the map from the temporary map to the info structure
static int	load_map_to_info_structure(t_info *info, char *tmp_map[])
{
	int	i;

	info->map = malloc(sizeof(char *) * (info->rows + 1));
	if (!info->map)
		return (1);
	i = 0;
	while (i < info->rows)
	{
		info->map[i] = tmp_map[i];
		i++;
	}
	info->map[info->rows] = NULL;
	info->loaded_elements++;
	return (0);
}

// Function that gets the map from the file and stores it in a temporary map
int	get_map_from_the_file(char *tmp_map[], t_info *info, int fd, char *line)
{
	while (line != NULL)
	{
		tmp_map[info->rows] = copy_line_from_file(line);
		if (!tmp_map[info->rows])
			return (1);
		free(line);
		line = get_next_line(fd);
		info->rows++;
	}
	return (0);
}

// Get_map : get the map from file with GNL and stores it in tmp_map
// Load_map_to_info_structure : Load the map from tmp_map to info->map
// Parse_map : Parse the map and check if the map is valid
int	get_and_parse_map(t_info *info, char *line, int fd)
{
	char	*tmp_map[1000];

	if (get_map_from_the_file(tmp_map, info, fd, line) == FAILURE)
		return (ERROR_MAP);
	if (load_map_to_info_structure(info, tmp_map) == FAILURE)
		return (ERROR_MAP);
	if (parse_map(info) == FAILURE)
		return (ERROR_MAP);
	return (0);
}
