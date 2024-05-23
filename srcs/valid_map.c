/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:53:05 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/23 17:42:03 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	create(t_data *data, int i, char **map_copy, char **map)
{
	int	j;

	j = 0;
	while (map[i][j] != '\0' && map[i][j] != '\n')
	{
		if ((i == 0 || i == (data->map->total_lines - 1) || j == 0 || j
				== (data->map->width - 1)) && map[i][j] == ' ')
			map_copy[i][j] = '.';
		else
			map_copy[i][j] = map[i][j];
		j++;
	}
	while (j < data->map->width)
	{
		if (j == (data->map->width - 1))
			map_copy[i][j] = '\0';
		else
			map_copy[i][j] = '.';
		j++;
	}
}

char	**create_copy_map(char **map, t_data *data)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (data->map->total_lines) + 1);
	if (!map_copy)
		exit_cub("Map malloc error\n", data);
	i = 0;
	while (map[i])
	{
		map_copy[i] = malloc(sizeof(char) * data->map->width);
		create(data, i, map_copy, map);
		i++;
	}
	map_copy[i] = '\0';
	return (map_copy);
}

static void	change_empyt_space(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i != 0 && map[i][j] == '.' && map[i - 1][j] == ' ')
				map[i - 1][j] = '.';
			if (map[i + 1] && map[i][j] == '.' && map[i + 1][j] == ' ')
				map[i + 1][j] = '.';
			if (map[i][j + 1] && map[i][j] == '.' && map[i][j + 1] == ' ')
				map[i][j + 1] = '.';
			if (j != 0 && map[i][j] == '.' && map[i][j - 1] == ' ')
				map[i][j - 1] = '.';
			j++;
		}
		i++;
	}
}

static int	check_around_point(char **map, char c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i != 0 && map[i][j] == '.' && map[i - 1][j] == c)
				res = 1;
			if (map[i + 1] && map[i][j] == '.' && map[i + 1][j] == c)
				res = 1;
			if (map[i][j + 1] && map[i][j] == '.' && map[i][j + 1] == c)
				res = 1;
			if (j != 0 && map[i][j] == '.' && map[i][j - 1] == c)
				res = 1;
			j++;
		}
		i++;
	}
	return (res);
}

int	valid_wall(char **map, t_data *data)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = create_copy_map(map, data);
	while (check_around_point(map_copy, ' ') == 1)
	{
		change_empyt_space(map_copy);
		i = 0;
		while (map_copy[i])
			i++;
		continue ;
	}
	if (check_around_point(map_copy, '0') || check_around_point(map_copy, 'N')
		|| check_around_point(map_copy, 'S')
		|| check_around_point(map_copy, 'W')
		|| check_around_point(map_copy, 'E'))
	{
		free_array(map_copy);
		exit_cub("Error: Map must be closed/surrounded by walls.\n", data);
	}
	free_array(map_copy);
	return (0);
}
