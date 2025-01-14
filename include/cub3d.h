/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:25:04 by jewu              #+#    #+#             */
/*   Updated: 2025/01/14 17:07:23 by jewu             ###   ########.fr       */
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

# define WIDTH 1300
# define HEIGHT 800
# define TILE_SIZE 64
# define FOV 60
# define ROT_SPEED 0.01
# define PI 3.14159265359

/* ****************************** */
/*          Structures            */
/* ****************************** */

typedef struct s_map_node
{
	char				*line;
	struct s_map_node	*next;
}						t_map_node;

typedef struct s_image
{
	void				*mlx_img;
	int					width;
	int					height;
}						t_image;

typedef struct s_ray
{
	double	ray_angle;
	double	distance;

	float	horizontal_x;
	float	horizontal_y;
	float	vertical_x;
	float	vertical_y;

	int		wall_flag;
	int		index;
}				t_ray;

typedef struct s_player
{
	int		p_x;
	int		p_y;

	double	angle;

	float	fov;
}				t_player;

typedef struct s_info
{
	t_image				*textures[4];
	t_ray				*ray;
	t_player			*player;

	int					floor_rgb[3];
	int					ceiling_rgb[3];
	int					loaded_elements;
	int					map_px;
	int					map_py;
	int					height;
	int					width;
	int					parsing_succeed;

	void				*mlx_ptr;
	void				*win_ptr;

	char				**map;
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
bool	check_borders(char **map, int height);
bool	is_map_line(char *line, t_info *info);

/*Initialization*/

int		init_everything(t_info *info);
int		handle_keypress(int key, t_info *info);
int		init_player(t_info *info, t_player *player);

//void	draw_player(t_info *info, t_player *player);
//void	draw_minimap(t_info *info, t_player *player);

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

t_image	*get_wall_texture_rendering(t_info *info, int wall_flag);

/* Error */
void	error(char *msg);

/* Free functions */
void	free_info(t_info *info);

int		free_everything(t_info *info);
int		close_and_exit(t_info *info);

/* Debug */
void	print_info(t_info *info);

#endif
