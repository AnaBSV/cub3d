/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:34:45 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/04 19:56:03 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_map_struct(t_map *map)
{
	int	i;

	i = 0;
	/*printf("Begin Line: %d\n", map->map_begin_line);
	printf("Total Lines: %d\n", map->total_lines);
	printf("Width: %d\n", map->width);
	printf("\n");
	
	printf("NO: %s", map->no);
	printf("SO: %s", map->so);
	printf("WE: %s", map->we);
	printf("EA: %s", map->ea);
	printf("\n");

	printf("F_str: %s", map->f_str);
	printf("C_str: %s", map->c_str);
	
	printf("F: %d|%d|%d\n", map->f[0], map->f[1], map->f[2]);
	printf("C: %d|%d|%d\n", map->c[0], map->c[1], map->c[2]);
	*/
	printf("\n");

	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}

void	init_player(t_data *data, int l, int c, char **map)
{
	//printf("5\n");
	if (map[l][c] == 'N')
	{
		data->player_dir_y = -1;
		data->player_plane_x = 0.66;
	}
	else if (map[l][c] == 'S')
	{
		data->player_dir_y = 1;
		data->player_plane_x = -0.66;
	}
	else if (map[l][c] == 'W')
	{
		data->player_dir_x = -1;
		data->player_plane_y = -0.66;
	}
	else if (map[l][c] == 'E')
	{
		data->player_dir_x = 1;
		data->player_plane_y = 0.66;
	}
	data->map->map[l][c] = '0';
}

void print_data_struct(t_data *data)
{
	(void)data;
}

void	windows_builder(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}



void	init(t_data *data)
{
	data->name = "Cub3d";
	data->map->map_begin_line = -1;
	data->map->total_lines = 0;
	data->map->width = 0;
	
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->ea = NULL;
	data->map->we = NULL;
	data->map->f = NULL;
	data->map->c = NULL;
	data->map->f_str = NULL;
	data->map->c_str = NULL;

	data->map->map = NULL;
	data->map->map_x = 0;
	data->map->map_y = 0;
	data->map->side = -1;
}


static int	game(t_data *data)
{
	//printf("%d %d %d\n", data->map->f[0], data->map->f[1], data->map->f[2]);
	int color = ((data->map->c[0] << 16) + (data->map->c[1] << 8) + data->map->c[2]);
	paint_vertical(data, 0, HEIGHT / 2, color);
	color = ((data->map->f[0] << 16) + (data->map->f[1] << 8) + data->map->f[2]);
	paint_vertical(data, HEIGHT / 2, HEIGHT, color);
	ray(data);
	draw(data);

	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map_infos;

	data.map = &map_infos;

	
	if (argc != 2)
	{
		printf("Invalids Arguments\n");
		return (1);
	}
	
	init(&data);
	(void)argv;
	
	read_map_configs(argv[1], &data);
	get_map(argv[1], &data);
	check_map(data.map->map, &data);
	valid_wall(data.map->map, &data);
	data.mlx = mlx_init();
	preload_resources(&data);
	print_map_struct(data.map);
	windows_builder(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	//mlx_hook(data.win, 17, (1L << 17), &pressed_translate, &data);
	mlx_hook(data.win, 2, (1L << 0), &pressed_key, &data);
	mlx_loop_hook(data.mlx, &game, &data);
	mlx_loop(data.mlx);
	return (0);
}