/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:25:04 by jewu              #+#    #+#             */
/*   Updated: 2025/01/15 15:47:43 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ****************************** */
/*     C language Libraries       */
/* ****************************** */

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
# include <stdbool.h>

# define NO 2
# define SO 3
# define WE 4
# define EA 5
# define F 6
# define C 7
# define FAILURE 1
# define SUCCESS 0
# define ERROR_MAP 2
# define VALID_MAP_CHARS "01NSEW"

/* ****************************** */
/*          Structures            */
/* ****************************** */

typedef struct s_image
{
	void				*mlx_img;
	int					width;
	int					height;
	int					id;
}						t_image;

typedef struct s_info
{
	t_image				*textures[4];
	int					floor_rgb[3];
	int					ceiling_rgb[3];
	void				*mlx_ptr;
	char				**map;
	int					loaded_elements;
	int					cols;
	int					rows;
	int					map_px;
	int					map_py;
}						t_info;

/* ****************************** */
/*          Functions             */
/* ****************************** */

/* Initisialition */
t_info	*init_info(void);

/* Parsing */
int		parsing(t_info *info, char **argv);
int		extract_data_from_file(t_info *info, char *line, int fd);
int		get_rgb(t_info *info, char *line, int identifier);
int		get_texture(t_info *info, char *line, int identifier);
int		get_and_parse_map(t_info *info, char *line, int fd);
int		parse_map(t_info *info);
int		ft_isspace(char c);
int		map_is_cub(char *argv);
int		check_identifier(t_info *info, char *line);
int		check_borders(t_info *info, char **map);
bool	is_map_line(char *line, t_info *info);
void	get_player_position(t_info *info);
bool	line_with_only_whitespace(char *line);

/* Error */
void	error(char *msg);

/* Free functions */
void	free_info(t_info *info);

/* Debug */
void	print_info(t_info *info);

#endif