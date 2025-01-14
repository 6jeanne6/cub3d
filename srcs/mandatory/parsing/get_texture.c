/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:29:49 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/13 15:00:44 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to check if the texture is already created
// Success if the texture is not created
// Failure if the texture is already created
static int	already_created(t_info *info, int identifier)
{
	if (identifier == NO)
	{
		if (info->textures[0]->mlx_img != NULL)
			return (FAILURE);
	}
	if (identifier == SO)
	{
		if (info->textures[1]->mlx_img != NULL)
			return (FAILURE);
	}
	if (identifier == WE)
	{
		if (info->textures[2]->mlx_img != NULL)
			return (FAILURE);
	}
	if (identifier == EA)
	{
		if (info->textures[3]->mlx_img != NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

// Function that loads the image from the path in the textures array
static int	get_image(t_info *info, char *texture, int identifier)
{
	int	width;
	int	rows;

	width = 32;
	rows = 32;
	if (already_created(info, identifier) == FAILURE)
		return (error("Double texture detected"), FAILURE);
	if (identifier == NO)
		info->textures[0]->mlx_img = mlx_xpm_file_to_image(
				info->mlx_ptr, texture, &width, &rows);
	else if (identifier == SO)
		info->textures[1]->mlx_img = mlx_xpm_file_to_image(
				info->mlx_ptr, texture, &width, &rows);
	else if (identifier == WE)
		info->textures[2]->mlx_img = mlx_xpm_file_to_image(
				info->mlx_ptr, texture, &width, &rows);
	else if (identifier == EA)
		info->textures[3]->mlx_img = mlx_xpm_file_to_image(
				info->mlx_ptr, texture, &width, &rows);
	info->loaded_elements += 1;
	return (0);
}

/* Function to extract the correct value of 
the texture depending on the identifier */
/* Example: If ID = NO, 
we know where to store the texture in the textures array (index 0) */
int	get_texture(t_info *info, char *line, int identifier)
{
	char	*texture;
	int		i;
	int		j;

	i = 0;
	while (line[i] && ft_isspace(line[i]) == 1)
		i++;
	j = i;
	while (line[j] && !ft_isspace(line[j]))
		j++;
	texture = malloc(sizeof(char) * (j - i + 1));
	if (!texture)
		return (error("Malloc failed"), FAILURE);
	ft_strlcpy(texture, &line[i], j - i + 1);
	if (get_image(info, texture, identifier) == FAILURE)
		return (free(texture), FAILURE);
	free(texture);
	return (SUCCESS);
}
