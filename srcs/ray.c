/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:27:07 by vlopes            #+#    #+#             */
/*   Updated: 2024/05/20 16:27:36 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ray(int i, t_data *data)
{
	double	cam_x;

	cam_x = 2 * i / (double)WIDTH - 1;
	data->ray_dir_x = data->player_dir_x + data->player_plane_x * cam_x;
	data->ray_dir_y = data->player_dir_y + data->player_plane_y * cam_x;
	data->map->map_x = (int)(data->player_x);
	data->map->map_y = (int)(data->player_y);
	if (data->ray_dir_x == 0)
		data->ray_delta_dist_x = 1e30;
	else
		data->ray_delta_dist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->ray_delta_dist_y = 1e30;
	else
		data->ray_delta_dist_y = fabs(1 / data->ray_dir_y);
}

void	init_dda(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->ray_step_x = -1;
		data->ray_side_dist_x = \
		(data->player_x - data->map->map_x) * data->ray_delta_dist_x;
	}
	else
	{
		data->ray_step_x = 1;
		data->ray_side_dist_x = \
		(data->map->map_x + 1.0 - data->player_x) * data->ray_delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->ray_step_y = -1;
		data->ray_side_dist_y = \
		(data->player_y - data->map->map_y) * data->ray_delta_dist_y;
	}
	else
	{
		data->ray_step_y = 1;
		data->ray_side_dist_y = \
		(data->map->map_y + 1.0 - data->player_y) * data->ray_delta_dist_y;
	}
}

void	improve_dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit != 1)
	{
		if (data->ray_side_dist_x < data->ray_side_dist_y)
		{
			data->ray_side_dist_x += data->ray_delta_dist_x;
			data->map->map_x += data->ray_step_x;
			data->map->side = X;
		}
		else
		{
			data->ray_side_dist_y += data->ray_delta_dist_y;
			data->map->map_y += data->ray_step_y;
			data->map->side = Y;
		}
		if (data->map->map[data->map->map_y][data->map->map_x] == '1')
			hit = 1;
	}
}

void	cal_dist(t_data *data)
{
	if (data->map->side == X)
		data->perp_wall_dist = data->ray_side_dist_x - data->ray_delta_dist_x;
	else
		data->perp_wall_dist = data->ray_side_dist_y - data->ray_delta_dist_y;
}

void	text_wall(int i, t_data *data)
{
	int	y;

	texture (data);
	map_texture (data);
	y = data->text_start;
	data->text_y = 0.0;
	while (y < data->text_end)
	{
		data->text_y = (int)data->text_pos & (data->height - 1);
		data->text_pos += data->ray_step;
		data->text_color = data->map->texture[data->text_num][data->height * \
		data->text_y + data->text_x];
		if (data->map->side == Y)
			data->text_color = (data->text_color >> 1) & 8355711;
		data->map->buffer[y][i] = data->text_color;
		y++;
	}
}
