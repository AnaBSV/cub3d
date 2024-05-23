/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:37 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/23 17:54:28 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*ft_strdup_map(char *str)
{
	int		len;
	int		i;
	char	*copy;

	i = 0;
	len = 0;
	while (is_end_of_line(str, len) == 1)
		len++;
	copy = malloc(sizeof(char) * (len + 1));
	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	get_2(t_data *data, int map_index, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (map_index < data->map->total_lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (i < data->map->map_begin_line)
		{
			i++;
			free (line);
			continue ;
		}
		data->map->map[map_index] = ft_strdup_map(line);
		free(line);
		map_index++;
		i++;
	}
	return (map_index);
}

int	get_map(char *filename, t_data *data)
{
	int		fd;
	int		map_index;

	map_index = 0;
	fd = open (filename, O_RDONLY);
	if (fd == -1)
		exit_cub("Failed to open and read file.\n", data);
	data->map->map = malloc(sizeof(char *) * (data->map->total_lines) + 1);
	map_index = get_2(data, map_index, fd);
	data->map->map[map_index] = '\0';
	return (0);
}

static int	check_2(t_data *data, char **map, int i, int player)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' '
				|| map[i][j] == '\n')
			j++;
		else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
		{
			data->player_x = (double)j + 0.5;
			data->player_y = (double)i + 0.5;
			init_player(data, i, j, map);
			player++;
			j++;
		}
		else
			exit_cub("Invalid map: unknown char\n", data);
	}
	return (player);
}

void	check_map(char **map, t_data *data)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		player = check_2(data, map, i, player);
		i++;
	}
	if (player != 1)
		exit_cub("Invalid map: Just one player is accepted\n", data);
}
