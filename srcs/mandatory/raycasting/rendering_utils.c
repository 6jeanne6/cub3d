/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:12:57 by jewu              #+#    #+#             */
/*   Updated: 2025/01/29 14:11:52 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//create colors
int	the_texture_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	put_texture_color(t_image *texture, float x_gap, float y_gap)
{
	int	the_color;
	int	x;
	int	y;

	x = fabsf(fmodf(x_gap, TILE_SIZE) * (texture->width / TILE_SIZE));
	y = fabsf(fmodf(y_gap, TILE_SIZE) * (texture->height / TILE_SIZE));
	the_color = texture->addr[y * texture->size_line + x
		* texture->bits_per_pixel / 8];
	the_color += texture->addr[y * texture->size_line + x
		* texture->bits_per_pixel / 8 + 1] << 8;
	the_color += texture->addr[y * texture->size_line + x
		* texture->bits_per_pixel / 8 + 2] << 16;
	return (the_color);
}

//put pixel with color at memory address of pixel
void	super_mlx_pixel_put(t_image *texture, int x, int y, int color)
{
	char	*dst;

	dst = texture->addr + (y * texture->size_line + x
			* (texture->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//return texture of a cardinal direction
t_image	*which_cardinal_direction(t_info *info, int direction)
{
	int	i;

	i = 0;
	while (info->textures[i])
	{
		if (info->textures[i]->id == direction)
			return (info->textures[i]);
		i++;
	}
	return (NULL);
}
