/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:24:44 by jewu              #+#    #+#             */
/*   Updated: 2025/01/06 17:38:35 by lnjoh-tc         ###   ########.fr       */
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
	info->parsing_succeed = 0;
	if (parsing(info, argv) == FAILURE)
	{
		info->parsing_succeed = 1;
		print_info(info);
		return (free_info(info), 1);
	}
	print_info(info);
	free_info(info);
	return (SUCCESS);
}
