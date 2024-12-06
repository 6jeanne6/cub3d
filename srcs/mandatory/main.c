/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:44 by jewu              #+#    #+#             */
/*   Updated: 2024/12/06 16:38:42 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 2 || argc > 2)
		return (1);
	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return(error(5), 1);
	info->mlx_ptr = mlx_init();
	parse_cubed(&info, argv);

	write(1, "CA MARCHE\n", 10);
	return (0);
}
