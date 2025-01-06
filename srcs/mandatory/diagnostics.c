/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagnostics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:37:10 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2025/01/06 17:00:16 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_info(t_info *info)
{
	int i;

	printf("\n");
	// Affichage des textures
	printf("More informations about the test :\n");
	printf("Textures:\n");
	for (i = 0; i < 4; i++)
	{
		if (info->textures[i])
			printf("Texture %d: %p\n", i, info->textures[i]->mlx_img);
		else
			printf("Texture %d: NULL\n", i);
	}
	printf("\n");


	printf("RGB : \n");
	// Affichage des couleurs du sol (floor)
	printf("Floor RGB: %d, %d, %d\n", info->floor_rgb[0], info->floor_rgb[1], info->floor_rgb[2]);
	// Affichage des couleurs du plafond (ceiling)
	printf("Ceiling RGB: %d, %d, %d\n", info->ceiling_rgb[0], info->ceiling_rgb[1], info->ceiling_rgb[2]);
	printf("\n");




	// Affichage du nombre de lignes (Height) et de la carte
	if (info->map)
	{
		for (i = 0; info->map[i]; i++)
			printf("Map [%d] : %s \n",i, info->map[i]);
	}
	else
	{
		printf("Map is NULL\n");
	}
	printf("Nb de lignes contenues dans la map = %d\n", info->height);


	printf("\n");
	// Affichage de la valeur de loaded_elements
	printf("Nombres d'éléments récupérées depuis le fichier  : %d/7\n", info->loaded_elements);
	if (info->parsing_succeed == 0)
		printf("\033[1;32mParsing succeeded\033[0m\n"); // Vert clair
	else
		printf("\033[1;31mParsing failed\033[0m\n");   // Rouge

}