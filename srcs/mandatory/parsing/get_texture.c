/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:29:49 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/27 16:44:04 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static void	get_adress(t_info *info, int identifier)
//{
//	if (identifier == NO)
//		info->textures[0]->addr = mlx_get_data_addr(info->textures[0]->mlx_img,
//				&info->textures[0]->bits_per_pixel,
//				&info->textures[0]->size_line, &info->textures[0]->endian);
//	else if (identifier == SO)
//		info->textures[1]->addr = mlx_get_data_addr(info->textures[1]->mlx_img,
//				&info->textures[1]->bits_per_pixel,
//				&info->textures[1]->size_line, &info->textures[1]->endian);
//	else if (identifier == WE)
//		info->textures[2]->addr = mlx_get_data_addr(info->textures[2]->mlx_img,
//				&info->textures[2]->bits_per_pixel,
//				&info->textures[2]->size_line, &info->textures[2]->endian);
//	else if (identifier == EA)
//		info->textures[3]->addr = mlx_get_data_addr(info->textures[3]->mlx_img,
//				&info->textures[3]->bits_per_pixel,
//				&info->textures[3]->size_line, &info->textures[3]->endian);
//}

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

// Function to check if the texture is already created
// Success if the texture is not created
// Failure if the texture is already created
//static int	already_created(t_info *info, int identifier)
//{
//	if (identifier == NO)
//	{
//		if (info->textures[0]->mlx_img != NULL)
//			return (FAILURE);
//	}
//	if (identifier == SO)
//	{
//		if (info->textures[1]->mlx_img != NULL)
//			return (FAILURE);
//	}
//	if (identifier == WE)
//	{
//		if (info->textures[2]->mlx_img != NULL)
//			return (FAILURE);
//	}
//	if (identifier == EA)
//	{
//		if (info->textures[3]->mlx_img != NULL)
//			return (FAILURE);
//	}
//	return (SUCCESS);
//}

// Function that loads the image from the path in the textures array
//static int	get_image(t_info *info, char *texture, int identifier)
//{
//	int	width;
//	int	rows;

//	width = 32;
//	rows = 32;
//	if (already_created(info, identifier) == FAILURE)
//		return (error("Double texture detected"), FAILURE);
//	if (identifier == NO)
//		info->textures[0]->mlx_img = mlx_xpm_file_to_image(
//				info->mlx_ptr, texture, &width, &rows);
//	else if (identifier == SO)
//		info->textures[1]->mlx_img = mlx_xpm_file_to_image(
//				info->mlx_ptr, texture, &width, &rows);
//	else if (identifier == WE)
//		info->textures[2]->mlx_img = mlx_xpm_file_to_image(
//				info->mlx_ptr, texture, &width, &rows);
//	else if (identifier == EA)
//		info->textures[3]->mlx_img = mlx_xpm_file_to_image(
//				info->mlx_ptr, texture, &width, &rows);
//	get_adress(info, identifier);
//	info->loaded_elements += 1;
//	return (0);
//}

static t_image	*get_address(t_info *info, char *path)
{
	t_image	*img;

	img = ft_calloc(1, sizeof(t_image));
	if (!img)
		close_and_exit(info);
	img->mlx_img = mlx_xpm_file_to_image(info->mlx_ptr, path,
			&img->width, &img->height);
	if (!img->mlx_img)
	{
		free(img);
		close_and_exit(info);
	}
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (img);
}

static int	get_image(t_info *info, char *texture, int identifier)
{
	static int	i;

	(void)identifier;
	//if (already_created(info, identifier) == FAILURE)
	//	return (error("Double texture detected"), FAILURE);
	info->textures[i]->mlx_img = get_address(info, texture);
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
	if (get_image(info, texture, identifier) == FAILURE)
		return (free(texture), FAILURE);
	setup_id(info, identifier);
	free(texture);
	return (SUCCESS);
}
