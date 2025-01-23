/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr >                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:44 by jewu              #+#    #+#             */
/*   Updated: 2025/01/23 16:35:21 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (error("Invalid number of arguments"), 1);
	info = init_info();
	if (!info)
		return (1);
	if (parsing(info, argv) == FAILURE)
		return (free_info(info), 1);
	if (init_everything(info) == 1)
		return (free_everything(info), 1);
	lets_execute_the_game(info);
	return (SUCCESS);
}
