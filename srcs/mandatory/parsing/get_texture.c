/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:29:49 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/02/02 17:07:21 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to setup the structure id of the texture
static int	setup_id(t_info *info, int identifier)
{
	if (identifier == NO)
		info->textures[0]->id = NO;
	else if (identifier == SO)
		info->textures[1]->id = SO;
	else if (identifier == WE)
		info->textures[2]->id = WE;
	else if (identifier == EA)
		info->textures[3]->id = EA;
	else
		return (FAILURE);
	return (SUCCESS);
}

static void	get_address(t_info *info, char *path, t_image *texture)
{
	texture->mlx_img = mlx_xpm_file_to_image(info->mlx_ptr, path,
			&texture->width, &texture->height);
	if (!texture->mlx_img)
	{
		close_and_exit(info);
	}
	texture->addr = mlx_get_data_addr(texture->mlx_img,
			&texture->bits_per_pixel, &texture->size_line,
			&texture->endian);
}

static int	get_image(t_info *info, char *texture)
{
	static int	i;

	get_address(info, texture, info->textures[i]);
	i++;
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
	if (get_image(info, texture) == FAILURE)
		return (free(texture), FAILURE);
	setup_id(info, identifier);
	free(texture);
	return (SUCCESS);
}
