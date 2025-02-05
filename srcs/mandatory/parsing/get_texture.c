/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:29:49 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/02/05 12:01:05 by jewu             ###   ########.fr       */
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

static void	get_address(t_info *info, char *path, t_image *texture,
char *og_line)
{
	static int	i;

	if (i < 4)
	{
		texture->mlx_img = mlx_xpm_file_to_image(info->mlx_ptr, path,
				&texture->width, &texture->height);
		i++;
	}
	if (!texture->mlx_img)
	{
		error("Something is wrong with your image");
		free(path);
		free(og_line);
		get_next_line(GNL_CLEAR);
		close_and_exit(info);
	}
	texture->addr = mlx_get_data_addr(texture->mlx_img,
			&texture->bits_per_pixel, &texture->size_line,
			&texture->endian);
}

//static void	get_address(t_info *info, char *path, char *og_line, int fd)
//{
//	static int	i;

//	if (i < 4)
//	{
//		info->textures[i]->mlx_img = mlx_xpm_file_to_image(info->mlx_ptr, path,
//				&info->textures[i]->width, &info->textures[i]->height);
//		i++;
//	}
//	if (!info->textures[i]->mlx_img)
//	{
//		error("Something is wrong with your image");
//		free(path);
//		free(og_line);
//		close(fd);
//		get_next_line(GNL_CLEAR);
//		close_and_exit(info);
//	}
//	info->textures[i]->addr = mlx_get_data_addr(info->textures[i]->mlx_img,
//			&info->textures[i]->bits_per_pixel, &info->textures[i]->size_line,
//			&info->textures[i]->endian);
//}

static int	get_image(t_info *info, char *texture, char *og_line)
{
	static int	i;

	get_address(info, texture, info->textures[i], og_line);
	i++;
	info->loaded_elements += 1;
	return (0);
}

/* Function to extract the correct value of 
the texture depending on the identifier */
/* Example: If ID = NO, 
we know where to store the texture in the textures array (index 0) */
int	get_texture(t_info *info, char *line, int identifier, char *og_line)
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
	if (get_image(info, texture, og_line) == FAILURE)
		return (free(texture), FAILURE);
	setup_id(info, identifier);
	free(texture);
	return (SUCCESS);
}

//int	get_texture(t_info *info, char *line, int identifier, int fd)
//{
//	char	*texture;
//	int		i;
//	int		j;

//	i = 0;
//	while (line[i + 2] && ft_isspace(line[i + 2]) == 1)
//		i++;
//	j = i;
//	while (line[j + 2] && !ft_isspace(line[j + 2]))
//		j++;
//	texture = malloc(sizeof(char) * (j - i + 1));
//	if (!texture)
//		return (error("Malloc failed"), FAILURE);
//	ft_strlcpy(texture, &line[i + 2], j - i + 1);
//	if (get_image(info, texture, line, fd) == FAILURE)
//		return (free(texture), FAILURE);
//	setup_id(info, identifier);
//	free(texture);
//	return (SUCCESS);
//}
