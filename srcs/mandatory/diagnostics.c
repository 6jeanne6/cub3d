/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagnostics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:37:10 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/15 15:47:52 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	print_info(t_info *info)
//{
//	int	i;

//	i = 0;
//	printf("\n");
//	printf("More information about the test :\n");
//	printf("Textures:\n");
//	while (i < 4)
//	{
//		if (info->textures[i])
//			printf("Texture %d: %p\n", i, info->textures[i]->mlx_img);
//		else
//			printf("Texture %d: NULL\n", i);
//		i++;
//	}
//	printf("\n");
//	printf("RGB : \n");
//	printf("Floor RGB: %d, %d, %d\n", info->floor_rgb[0],
//		info->floor_rgb[1], info->floor_rgb[2]);
//	printf("Ceiling RGB: %d, %d, %d\n", info->ceiling_rgb[0],
//		info->ceiling_rgb[1], info->ceiling_rgb[2]);
//	printf("\n");
//	if (info->map)
//	{
//		i = 0;
//		while (info->map[i])
//		{
//			printf("Map [%d] : %s \n", i, info->map[i]);
//			i++;
//		}
//	}
//	else
//	{
//		printf("Map is NULL\n");
//	}
//	printf("Nb de lignes contenues dans la map = %d\n", info->rows);
//	printf("\n");
//	printf("Nombres d'éléments récupérées depuis le fichier  :%d/7\n",
//		info->loaded_elements);
//	if (info->parsing_succeed == 0)
//		printf("\033[1;32mParsing succeeded\033[0m\n");
//	else
//		printf("\033[1;31mParsing failed\033[0m\n");
//}
