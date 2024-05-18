#include "../includes/cub3d.h"

void	paint_vertical(t_data *data, int start_y, int end_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = 0;
		while (x < WIDTH)
			data->map->buffer[y][x++] = color;
		y++;
	}
}

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			data->addr[y * WIDTH + x] = data->map->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	ray(t_data *data)
{
    int i;

    i = 0;
    while(i < WIDTH)
    {
		init_ray(i, data);
		init_dda(data);
		improve_dda(data);
		cal_dist(data);
		text_wall(i, data);
		i++;
    }
 }