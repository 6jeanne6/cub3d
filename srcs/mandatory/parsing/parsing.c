/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:44:12 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2024/12/06 12:51:55 by lnjoh-tc         ###   ########.fr       */
/*                                                                          */
/* ************************************************************************** */

#include "cub3d.h"

// Check if the textures, ceilings, floors and map are correcly loaded
static int	is_all_ok(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!info->textures[i]->mlx_img)
			return (error("Something is wrong with textures"), FAILURE);
	}
	i = -1;
	while (++i < 3)
	{
		if (info->ceiling_rgb[i] == -1)
			return (error("Something is wrong with ceilings"), FAILURE);
	}
	i = -1;
	while (++i < 3)
	{
		if (info->floor_rgb[i] == -1)
			return (error("Something is wrong with floors"), FAILURE);
	}
	if (info->map == NULL)
		return (error("Something is wrong with map"), FAILURE);
	return (SUCCESS);
}

// Function that read file and extract data from it
// info->loaded 7 means map is loaded so no need to free line
static int	read_and_extract(t_info *info, int fd)
{
	char	*line;
	int		return_value;

	line = get_next_line(fd);
	if (!line)
		return (error("Empty file"), FAILURE);
	while (line)
	{
		if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		return_value = extract_data_from_file(info, line, fd);
		if (return_value == FAILURE)
			return (get_next_line(-42), free(line), FAILURE);
		else if (return_value == ERROR_MAP)
			return (get_next_line(-42), FAILURE);
		if (info->loaded_elements != 7)
			free (line);
		line = get_next_line(fd);
	}
	return (SUCCESS);
}

// Function that open the file ,read the file, and check if everything is good
int	parsing(t_info *info, char **argv)
{
	int	fd;

	fd = 0;
	if (map_is_cub(argv[1]) == FAILURE)
		return (error("File is not a .cub extension"), FAILURE);
	fd = open(argv[1], fd, O_RDONLY);
	if (fd < 0)
		return (error(strerror(errno)), FAILURE);
	if (read_and_extract(info, fd) == FAILURE)
		return (close(fd), FAILURE);
	if (is_all_ok(info) == FAILURE)
		return (close(fd), FAILURE);
	close(fd);
	return (SUCCESS);
}
