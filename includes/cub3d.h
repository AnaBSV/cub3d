/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:34:42 by ade-sous          #+#    #+#             */
/*   Updated: 2024/04/20 20:31:02 by ade-sous         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 800

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
	
}	t_map;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*name;
	t_map		*map;
	
}	t_data;


void	windows_builder(t_data *data);
int		close_window(int code, t_data *data);

int		read_map_configs(char *filename, t_data *data);

void	free_array(char **arr);
void	free_map(t_map *map);


int		count_char(char *str, char c);
void	exit_cub(char *str, t_data *data);
int		is_empty_line(char *str);

#endif