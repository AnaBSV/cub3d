/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:37 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/23 17:17:59 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	remove_texture_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
}

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	read_3(t_data *data, int total_configs, char *line, int i)
{
	int	is_config_line;

	is_config_line = 0;
	if (total_configs == 6)
	{
		if (data->map->map_begin_line == -1)
			data->map->map_begin_line = i;
		if (ft_strlen(line) > (data->map->width))
			data->map->width = ft_strlen(line);
		data->map->total_lines++;
	}
	is_config_line = check_config_line(line, data, total_configs);
	if (total_configs <= 5 && !is_config_line)
		total_configs++;
	else if (total_configs <= 5 && is_config_line)
	{
		free(line);
		exit_cub("Erro nas Configurações A\n", data);
	}
	return (total_configs);
}

static int	read_2(t_data *data, char *line, int fd)
{
	int	i;
	int	total_configs;

	i = 0;
	total_configs = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (!is_empty_line(line) || total_configs < 0)
		{
			i++;
			free (line);
			continue ;
		}
		total_configs = read_3(data, total_configs, line, i);
		free(line);
		i++;
	}
	return (total_configs);
}

int	read_map_configs(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	int		total_configs;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_cub("Failed to open and read file.\n", data);
	total_configs = read_2(data, line, fd);
	close(fd);
	if (total_configs != 6)
		exit_cub("Erro nas Configurações B\n", data);
	data->map->c = get_color_info(data->map->c_str, 'C', data);
	data->map->f = get_color_info(data->map->f_str, 'F', data);
	remove_texture_nl(data->map->no);
	remove_texture_nl(data->map->so);
	remove_texture_nl(data->map->ea);
	remove_texture_nl(data->map->we);
	return (0);
}
