/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:25:04 by jewu              #+#    #+#             */
/*   Updated: 2025/01/08 15:41:27 by jewu             ###   ########.fr       */
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
# define WIDTH 1500
# define HEIGHT 1000
# define TILE_SIZE 42

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

typedef struct s_player
{
	int	width;
	int	height;
	int	x;
	int	y;
}				t_player;

typedef struct s_info
{
	t_image				*textures[4];
	t_player			*player;
	int					floor_rgb[3];
	int					ceiling_rgb[3];
	void				*mlx_ptr;
	void				*win_ptr;
	char				**map;
	int					loaded_elements;
	int					height;
	int					width;
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
int		check_identifier(t_info *info, char *line);
bool	check_borders(char **map, int height);
bool	is_map_line(char *line, t_info *info);

/*Initialization*/

int		init_everything(t_info *info, t_player *player);
int		handle_keypress(int key, t_info *info);

void	draw_player(t_info *info, t_player *player);
void	draw_minimap(t_info *info, t_player *player);

/* Error */
void	error(char *msg);

/* Free functions */
void	free_info(t_info *info);

int		free_everything(t_info *info);
int		close_and_exit(t_info *info);

/* Debug */
void	print_info(t_info *info);

#endif
