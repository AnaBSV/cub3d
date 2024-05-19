/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:27:33 by vlopes            #+#    #+#             */
/*   Updated: 2024/05/18 20:37:10 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_color_texture(t_data *data)
{
	if (data->map->side == Y && data->ray_dir_y < 0)
	{
		data->height = data->h4;
		data->width = data->w4;
		data->text_num = 3;
	}
	if (data->map->side == Y && data->ray_dir_y > 0)
	{
		data->height = data->h3;
		data->width = data->w3;
		data->text_num = 2;
	}
	if (data->map->side == X && data->ray_dir_x < 0)
	{
		data->height = data->h2;
		data->width = data->w2;
		data->text_num = 1;
	}
	if (data->map->side == X && data->ray_dir_x > 0)
	{
		data->height = data->h4;
		data->width = data->w4;
		data->text_num = 0;
	}
}

void	map_texture(t_data *data)
{
	data->text_x = (data->text_wall_x * data->width);
	if (data->map->side == X && data->ray_dir_x > 0)
		data->text_x = data->width - data->text_x - 1;
	if (data->map->side == Y && data->ray_dir_y < 0)
		data->text_x = data->width - data->text_x - 1;
	data->ray_step = 1.0 * data->height / data->ray_line_height;
	data->text_pos = (data->text_start - HEIGHT / 2 \
	+ data->ray_line_height / 2) * data->ray_step;
}

void	texture(t_data *data)
{
	data->ray_line_height = (int)(HEIGHT / data->perp_wall_dist);
	data->text_start = -data->ray_line_height / 2 + HEIGHT / 2;
	if (data->text_start < 0)
		data->text_start = 0;
	data->text_end = HEIGHT / 2 + data->ray_line_height / 2;
	if (data->text_end >= HEIGHT)
		data->text_end = HEIGHT - 1;
	get_color_texture(data);
	if (data->map->side == X)
		data->text_wall_x = data->player_y + \
		(data->perp_wall_dist * data->ray_dir_y);
	else
		data->text_wall_x = data->player_x + \
		(data->perp_wall_dist * data->ray_dir_x);
	data->text_wall_x -= floor(data->text_wall_x);
}
