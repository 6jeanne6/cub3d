/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:44 by jewu              #+#    #+#             */
/*   Updated: 2025/02/02 17:10:09 by lnjoh-tc         ###   ########.fr       */
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
	{
		info->parsing_succeed = FAILURE;
		return (free_info(info), 1);
	}
	if (init_window(info) == 1)
		close_and_exit(info);
	lets_execute_the_game(info);
	return (SUCCESS);
}
