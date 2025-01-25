/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:12:57 by jewu              #+#    #+#             */
/*   Updated: 2025/01/25 15:52:38 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//create colors
int	the_texture_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

//put a RGB pixel color by getting the byte of the pixel at (x, y)
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
	printf("dst is: %p\n", dst);
	printf("texture is: %p\n", texture);
	printf("texture addr is: %p\n", texture->addr);
	printf("texture size line is: %d\n", texture->size_line);
	printf("texture bits per pixel is: %d\n", texture->bits_per_pixel);
	printf("color is: %d\n", color);
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
			return (info->textures[i]->mlx_img);
		i++;
	}
	return (NULL);
}
