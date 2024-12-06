/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnjoh-tc <lnjoh-tc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:25:04 by jewu              #+#    #+#             */
/*   Updated: 2024/12/06 16:34:56 by lnjoh-tc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// **********************************
// *      C language Libraries      *
// **********************************

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>

# define  NO 1
# define  SO 2
# define  WE 3
# define  EA 4
# define  F 5
# define  C 6


// **********************************
// *          Structures            *
// **********************************

typedef struct s_image
{
	void	*mlx_img;

	int		width;
	int		height;

} t_image

typedef struct s_info
{
	t_image	*textures[4];
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	void	*mlx_ptr;
	char	**map;
	int		flag;
	int		heigth;
	int		length;

} t_info

// **********************************
// *          Functions             *
// **********************************

int	parse_cubed(t_info *info, char **argv);
int	ft_isspace(char c);

int	get_rgb(t_info *info, char *line, int identifier);
int	get_texture(t_info *info, char *line, int identifier);

#endif

