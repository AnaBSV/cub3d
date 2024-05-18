/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:34:42 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/04 19:31:46 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"
#include "./get_next_line.h"
#include "./libft.h"
#include <fcntl.h>

#include <stdlib.h>
#include <math.h>
#include <stdio.h> //remove
#include <unistd.h>

# define WIDTH 1900
# define HEIGHT 1000
# define TEXWIDTH 256
# define TEXHEIGHT 256
# define X 0
# define Y 1
# define ROT_SPEED 0.06
# define MOVE_SPEED 0.06

typedef struct	s_map {
	char		*no;
	char		*so;
	char		*we;
	char		*ea;

	char		*f_str;
	char		*c_str;
	
	int			*f;
	int			*c;

	char		**map;
	
	int 		map_begin_line;
	int			total_lines;
	int			width;

	int			buffer[HEIGHT][WIDTH];
	int			*texture[4];

	//RAYCASTING
	int map_x;
	int map_y;
	int	side;

}	t_map;


typedef struct	s_data {
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*name;
	double		player_x;
	double		player_y;
	t_map		*map;

	//Texture
	int			width;
	int			height;
	int				w1;
	int				h1;
	int				w2;
	int				h2;
	int				w3;
	int				h3;
	int				w4;
	int				h4;

	//RAYCASTING
	double	dir_x;
	double	dir_y;
	double	player_dir_x;
	double	player_dir_y;
	double	player_plane_x;
	double	player_plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	ray_delta_dist_x;
	double	ray_delta_dist_y;
	int		ray_step_x;
	int		ray_step_y;
	double	ray_side_dist_x;
	double	ray_side_dist_y;
	double	perp_wall_dist;
	double	ray_step;
	int		ray_line_height;

	//TEXTURE
	int		text_start;
	int		text_end;
	int		text_x;
	int		text_y;
	double	text_pos;
	int		text_color;
	int		text_num;
	double	text_wall_x;

}	t_data;

void	free_array(char **arr);
void	free_map(t_map *map);

int		count_char(char *str, char c);
void	exit_cub(char *str, t_data *data);
int		is_empty_line(char *str);

int		valid_wall(char **map, t_data *data);
void	preload_resources(t_data *data);

int		close_window(int code, t_data *data);
int		read_map_configs(char *filename, t_data *data);
int		get_map(char *filename, t_data *data);
void	check_map(char **map, t_data *data);
void	paint_vertical(t_data *data, int start_y, int end_y, int color);
void	draw(t_data *data);

void	ray(t_data *data);
void	init_player(t_data *data, int l, int c, char **map);
void	init_dda(t_data *data);
void	improve_dda(t_data *data);
void	cal_dist(t_data *data);
void	text_wall(int i, t_data *data);

int is_end_of_line(char *line, int col);

void	init_ray(int i, t_data *data);
void	move_player(t_data *data, int n, char *dir);
void	rotate(t_data *data, int n);

int	pressed_key(int key, t_data *data);


//void	init_texture(t_data *data);
void	map_texture(t_data *data);
void	texture(t_data *data);

#endif