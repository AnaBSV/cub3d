#ifndef CUB3D_H
# define CUB3D_H

#include "../minilibx-linux/mlx.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h> //remove
#include <unistd.h>

# define WIDTH 1000
# define HEIGHT 800

typedef struct	s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*name;
}	t_data;


void	windows_builder(t_data *data);

#endif