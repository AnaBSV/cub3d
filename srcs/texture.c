#include "../includes/cub3d.h"

void	load_w_h(int index, t_data *data, int w, int h)
{
	if (index == 0)
	{
		data->h1 = h;
		data->w1 = w;
	}
	else if (index == 1)
	{
		data->h2 = h;
		data->w2 = w;
	}
	else if (index == 2)
	{
		data->h3 = h;
		data->w3 = w;
	}
	else if (index == 3)
	{
		data->h4 = h;
		data->w4 = w;
	}
}

void	load_image(t_data *data, int *tex, char *tex_path, int index)
{
	int	i;
	int	j;

	i = -1;
    data->img = NULL;
	data->img = \
	mlx_xpm_file_to_image(data->mlx, tex_path, &data->width, &data->height);
    printf("data->mlx: %p %s| tex_path: %s | data->width: %d | data->height: %d\n", data->img, data->img ? "ok":"vazio", tex_path, data->width, data->height);
	if (data->img == NULL)
		exit_cub("XPM file error.\n", data);
	data->addr = (char *)mlx_get_data_addr(data->img, \
	&data->bits_per_pixel, &data->line_length, &data->endian);
	load_w_h(index, data, data->width, data->height);
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			tex[data->width * i + j] = data->addr[data->width * i + j];
	}
	mlx_destroy_image(data->mlx, data->img);
}

void	load_all_tex(t_data *data)
{
    printf("NO: %s", data->map->no);
	printf("SO: %s", data->map->so);
	printf("WE: %s", data->map->we);
	printf("EA: %s", data->map->ea);

	load_image(data, data->map->texture[0], data->map->no, 0);
	load_image(data, data->map->texture[1], data->map->so, 1);
	load_image(data, data->map->texture[2], data->map->we, 2);
	load_image(data, data->map->texture[3], data->map->ea, 3);
}


void	preload_resources(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->map->buffer[y][x] = 0;
			x++;
		}
		if (y < 4)
		{
			data->map->texture[y] = (int *)malloc(sizeof(int) * TEXWIDTH * TEXHEIGHT);
			if (!data->map->texture[y])
				exit_cub("Failed to allocate memory for texture address\n", data);
		}
		if (y < 4 && !data->map->texture[y])
			exit_cub("Texture missing or failed to load.\n", data);
		y++;
	}
	load_all_tex(data);
}