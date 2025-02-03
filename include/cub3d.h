/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:25:04 by jewu              #+#    #+#             */
/*   Updated: 2025/02/03 11:24:26 by jewu             ###   ########.fr       */
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

# define VALID_MAP_CHARS "01NSEW"

# define WIDTH 900
# define HEIGHT 900
# define TILE_SIZE 64
# define FOV 60
# define ROT_SPEED 0.1
# define PLAYER_SPEED 5
# define PI 3.14159265359
# define GNL_CLEAR -42

/* ****************************** */
/*          Structures            */
/* ****************************** */

enum	e_error
{
	SUCCESS,
	FAILURE,
	ERROR_MAP
};

enum	e_texture
{
	NO = 2,
	SO,
	WE,
	EA,
	F,
	C
};

enum	e_movement
{
	GO_LEFT = 42,
	GO_RIGHT,
	GO_UP,
	GO_DOWN,
	ROTATE_LEFT,
	ROTATE_RIGHT
};

typedef struct s_ray
{
	double	ray_angle;
	double	distance;

	float	horizontal_x;
	float	horizontal_y;
	float	vertical_x;
	float	vertical_y;

	int		horizontal_flag;
	int		index;
}				t_ray;

typedef struct s_player
{
	int		p_x;
	int		p_y;

	double	angle;

	float	fov;
}				t_player;

typedef struct s_image
{
	void				*mlx_img;

	char				*addr;

	int					width;
	int					height;
	int					bits_per_pixel;
	int					endian;
	int					tile_size;
	int					size_line;
	int					id;
}						t_image;

typedef struct s_info
{
	t_image				*textures[4];
	t_ray				*ray;
	t_player			*player;
	t_image				img;

	int					floor_rgb[3];
	int					ceiling_rgb[3];
	int					loaded_elements;
	int					cols;
	int					rows;
	int					map_px;
	int					map_py;
	int					screen_width;
	int					screen_height;
	int					go_up_down;
	int					go_left_right;
	int					rotation_left_right;
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
int		get_texture(t_info *info, char *line, int identifier, char *og_line);
int		get_and_parse_map(t_info *info, char *line, int fd);
int		parse_map(t_info *info);
int		ft_isspace(char c);
int		map_is_cub(char *argv);
int		get_identifier(t_info *info, char *line);
int		check_borders(t_info *info, char **map);

bool	is_map_line(char *line, t_info *info);
bool	line_with_only_whitespace(char *line);

void	get_player_position(t_info *info);

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
t_image	*which_cardinal_direction(t_info *info, int direction);

int		put_texture_color(t_image *texture, float x_gap, float y_gap);
int		the_texture_rgb(int red, int green, int blue);

/*Execution*/
void	lets_execute_the_game(t_info *info);
void	keyboard_hook(t_info *info);
void	the_player_moves(t_info *info, double x_move, double y_move);
void	the_player_rotates(t_info *info, int right);
void	i_can_move(t_info *info, double x_move, double y_move);
void	free_textures(t_info *info);
void	init_img(t_info *info);

int		handle_keypress(int key, t_info *info);
int		handle_keyrelease(int key, t_info *info);
int		init_window(t_info *info);

/* Error */
void	error(char *msg);

/* Free functions */
int		free_everything(t_info *info);
int		close_and_exit(t_info *info);

void	free_info(t_info *info);

/* Debug */
//void	print_info(t_info *info);

#endif
