#include "../includes/cub3d.h"

void	windows_builder(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	init(t_data *data)
{
	data->name = "Cub3d";
}

int main (void)
{
	t_data	data;

    printf("rodando a main\n");

	init(&data);

	windows_builder(&data);
	mlx_loop(data.mlx);

}