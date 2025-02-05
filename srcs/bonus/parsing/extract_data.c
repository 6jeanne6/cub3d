/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:59:04 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/02/05 12:00:27 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Function that allows us to return the identifier
static int	return_id(int i)
{
	if (i == 0)
		return (NO);
	if (i == 1)
		return (SO);
	if (i == 2)
		return (WE);
	if (i == 3)
		return (EA);
	if (i == 4)
		return (F);
	if (i == 5)
		return (C);
	return (FAILURE);
}

// Function that get the identifier of the line
int	get_identifier(t_info *info, char *line)
{
	char	*valid_identifiers[7];
	int		i;

	if (info->loaded_elements == 6)
		return (SUCCESS);
	valid_identifiers[0] = "NO";
	valid_identifiers[1] = "SO";
	valid_identifiers[2] = "WE";
	valid_identifiers[3] = "EA";
	valid_identifiers[4] = "F";
	valid_identifiers[5] = "C";
	valid_identifiers[6] = NULL;
	i = 0;
	while (valid_identifiers[i] != NULL)
	{
		if (ft_strncmp(line, valid_identifiers[i],
				ft_strlen(valid_identifiers[i])) == 0)
			return (return_id(i));
		i++;
	}
	error("Invalid identifier/character detected in file\n"
		"Please be sure that the file is correctly formatted\n"
		"Valid identifiers are: NO, SO, WE, EA, F, C\n"
		"The map is at the ending of the file");
	return (FAILURE);
}

/* Function that analyse line
1 : Skip spaces at the beginning of the line
2 : If load_elements != 6, its means we not charge all elements 
	(We need all elements to charge the map)
		2-1 : Get the identifier
		2-2: If the identifier is valid, get the texture or color
3 : If load_elements == 6, its means we have all elements
		3-1 : Get and parse the map
*/
int	extract_data_from_file(t_info *info, char *line, int fd)
{
	int	i;
	int	id;
	int	return_value;

	i = 0;
	return_value = 0;
	while (line[i] != '\0' && ft_isspace(line[i]) == 1)
		i++;
	if (line_with_only_whitespace(line) == true)
		return (SUCCESS);
	if (info->loaded_elements != 6)
	{
		id = get_identifier(info, &line[i]);
		if (id == FAILURE)
			return (FAILURE);
		if (id == NO || id == SO || id == WE || id == EA)
			return_value = get_texture(info, &line[i + 2], id, line);
		if (id == F || id == C)
			return_value = get_rgb(info, &line[i + 1], id);
		return (return_value);
	}
	if (info->loaded_elements == 6 && is_map_line(line, info, &return_value))
		return_value = get_and_parse_map(info, line, fd);
	return (return_value);
}
