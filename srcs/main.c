/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:34:45 by ade-sous          #+#    #+#             */
/*   Updated: 2024/04/18 17:18:54 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void print_map_struct(t_map *map)
{
	printf("Begin Line: %d\n", map->map_begin_line);
	printf("Total Lines: %d\n", map->total_lines);
	printf("Width: %d\n", map->width);
	
	printf("NO: %s\n", map->no);
	printf("SO: %s\n", map->so);
	printf("WE: %s\n", map->we);
	printf("EA: %s\n", map->ea);


	printf("F: %d  %d  %d\n", map->f[0], map->f[1], map->f[2]);
	printf("C: %d  %d  %d\n", map->c[0], map->c[1], map->c[2]);
	
}

void print_data_struct(t_data *data)
{
	(void)data;
}

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
	data->map->map_begin_line = -1;
	data->map->total_lines = 0;
	data->map->width = 0;
	
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->ea = NULL;
	data->map->we = NULL;
	data->map->f = NULL;
	data->map->c = NULL;

}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map		map_infos;

	data.map = &map_infos;

	
	if (argc != 2)
	{
		printf("Invalids Arguments\n");
		return (1);
	}
	
	init(&data);
	
	read_map(argv[1], &data);
	print_map_struct(data.map);
	free_map(data.map);
	//windows_builder(&data);
	//mlx_hook(data.win, 17, 0, close_window, &data);
	//mlx_loop(data.mlx);
	return (0);
}
