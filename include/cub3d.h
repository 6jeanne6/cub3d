/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:25:04 by jewu              #+#    #+#             */
/*   Updated: 2025/01/23 15:48:12 by marvin           ###   ########.fr       */
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
	char				*addr;
	int					bits_per_pixel;
	int					endian;
	int					tile_size;
	int					size_line;
}						t_image;

typedef struct s_info
{
	t_image				*textures[4];
	int					floor_rgb[3];
	t_image				img;
	int					ceiling_rgb[3];
	void				*mlx_ptr;
	char				**map;
	int					loaded_elements;
	int					cols;
	int					rows;
	int					map_px;
	int					map_py;
	int					parsing_succeed;
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
int		get_identifier(t_info *info, char *line);
int		check_borders(t_info *info, char **map);

bool	is_map_line(char *line, t_info *info);
bool	line_with_only_whitespace(char *line);

void	get_player_position(t_info *info);

/*Initialization*/
int		init_everything(t_info *info);
int		init_player(t_info *info, t_player *player);
int		handle_keypress(int key, t_info *info);

/*Raycasting*/
void	raycasting(t_info *info, t_ray *ray);

int		check_intersection(double angle, float *inter, float *step, bool is_h);
int		is_right_zone(float angle, char c);
int		hit_the_wall(t_info *info, float x, float y);

double	normal_angle(double angle);

float	get_h_line_intersection(t_info *info, float angle);
float	get_v_line_intersection(t_info *info, float angle);

/*Rendering*/
void	wall_rendering(t_info *info, int rayon);
void	super_mlx_pixel_put(t_image *texture, int x, int y, int color);

float	get_x_gap(t_info *info, t_image *texture);

t_image	*get_wall_texture_rendering(t_info *info, int hori_flag);
t_image	*which_cardinal_direction(t_info *info, char *direction);

int		the_texture_color(t_image *texture, float x_gap, float y_gap);

/* Error */
void	error(char *msg);

/* Free functions */
int		free_everything(t_info *info);
int		close_and_exit(t_info *info);

void	free_info(t_info *info);

/* Debug */
//void	print_info(t_info *info);

#endif
