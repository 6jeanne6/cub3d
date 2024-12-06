/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:29:49 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2024/12/06 16:34:43 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_rgb(t_info *info, char *line, int identifier)
{
	int	i;
	char *tmp_rgb;
	int j;

	i = 0;
	j = 0;
	while(ft_isspace(line[i]) == 1)
		i++;
	while(ft_isspace(line[i]) == 0)
		j++;
	
		
}


static void load_image(t_info *info, char *line, int identifier)
{
	if (identifier == NO)
		info->textures[0]->mlx_img = mlx_xpm_file_to_image(info->mlx_ptr, tmp_texture, &x, &y);
	if (identifier == SO)
		info->textures[1]->mlx_img = mlx_xpm_file_to_image(info->mlx_ptr, tmp_texture, &x, &y);
	if (identifier == WE)
		info->textures[2]->mlx_img = mlx_xpm_file_to_image(info->mlx_ptr, tmp_texture, &x, &y);
	if (identifier == EA)
		info->textures[3]->mlx_img = mlx_xpm_file_to_image (info->mlx_ptr, tmp_texture, &x, &y);
}
int get_texture(t_info *info, char *line, int identifier)
{
	char 	*texture;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(ft_isspace(line[i]) == 1)
		i++;
	while(ft_isspace(line[i]) == 0)
		j++;
	tmp_texture = malloc(sizeof(char) * (j - i) + 1);
	if (!tmp_texture)
		return(error(5), 1);
	tmp_texture = ft_strlcpy(tmp_texture, &line[i], j - i);
	if (identifier == NO)
		load_image(info, line, NO);
	if (identifier == SO)
		load_image(info, line, NO);
	if (identifier == WE)
		load_image(info, line, NO);
	if (identifier == EA)
		load_image(info, line, NO);
	return (0);
}
