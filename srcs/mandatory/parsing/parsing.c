/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:44:12 by lnjoh-tc          #+#    #+#             */
/*   Updated: 2024/12/06 12:51:55 by lnjoh-tc         ###   ########.fr       */
/*                                                                          */
/* ************************************************************************** */

#include "cub3d.h"

void error (int error)
{
	if (error == 1)
		ft_putstr_fd("Error \n File is not .cub\n", 2);
	if (error == 2)
		ft_putstr_fd("Error \n Invalid map\n", 2);
	if (error == 3)
		ft_putstr_fd("Error \n Invalid identifier\n", 2);
	if (error == 4)
		ft_putstr_fd("Error \n Empty file\n", 2);
	if (error == 5)
		ft_putstr_fd("Error \n Malloc failed\n", 2);
}

static int	map_is_cub(char *argv)
{
	int	len;
	int	i;

	len = ft_strlen(argv);
	i = 0;
	if (len < 4)
		return (-1);
	while (argv[i] != '.')
		i++;
	if (ft_strncmp(argv + len, ".cub", 4) == 0
		|| ft_strncmp(argv + i, ".cub", len - i) == 0)
		return (1);
	else
		return (-1);
}

static int	analyse_line(t_info *info, char *line)
{
	int return_value;
	int i;

	i = 0;
	return_value = 0;
	if (ft_strlen(line) > 3)
		return (1);
	if (line[i] == "N" && line[i + 1] ==  "O" && !ft_isspace[i + 2])
		return_value = get_texture(info, &line[i+2], NO);
	if (line[i] == "S" && line[i + 1] ==  "O" && !ft_isspace[i + 2])
		return_value = get_texture(info, &line[i+2], SO);
	if (line[i] == "W" && line[i + 1] ==  "E" && !ft_isspace[i + 2])
		return_value = get_texture(info, &line[i+2], WE);
	if (line[i] == "E" && line[i + 1] ==  "A" && !ft_isspace[i + 2])
		return_value =get_texture(info, &line[i+2], EA);
		if (ft_strlen(line) > 2)
		return (1);
	if (line[i] == "F" && ft_isspace[i + 1])
		return_value = get_rgb(info, &line[i+1], F);
	if (line[i] == "C" && ft_isspace[i + 1])
		return_value = get_rgb(info, &line[i+1], C);
	if (ft_isdigit(line[i] && info->flag == 6))
	
	return (return_value);
}

static int  extract_and_analyse_line(t_info *info, int fd)
{
	char *line;
	int i;

	line = get_next_line(fd);
	if (!line)
		return(error(4), 1)
	while (line)
	{
		i = 0;
		while(ft_isspace(line[i]) == 1)
			i++;
		analyse_line(info, &line[i]);
		get_next_line(line);
	}
}

int	parse_cubed(t_info *info, char **argv)
{
	int	fd;

	if (map_is_cub(argv[1]) == 1)
		return (error(1), 1);
	fd = open(argv[1],fd,O_RDONLY)
	if (fd < 0)
		perror("Error\n");
	if (extract_and_analyse_line(info, fd) == 1)
	{
		close(fd);
		return (1)
	}
	return(0;)
}
