/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:31:24 by vlopes            #+#    #+#             */
/*   Updated: 2024/05/23 17:18:42 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get(t_data *data, int *colors, int i, char *ptr)
{
	while (ptr && *ptr != '\0' && i < 3)
	{
		colors[i] = ft_atoi(ptr);
		if (colors[i] < 0 || colors[i] >= 255)
			exit_cub("Invalid Color Info\n", data);
		ptr = ft_strchr(ptr, ',');
		if (ptr == NULL)
			break ;
		ptr++;
		while (ptr && *ptr == ' ')
			ptr++;
		i++;
	}
}

int	*get_color_info(char *line, char c, t_data *data)
{
	char				*ptr;
	int					*colors;
	int					i;

	ptr = ft_strchr(line, c);
	if (!ptr || count_char(line, ',') != 2)
		exit_cub("Invalid Color Info 1\n", data);
	colors = malloc(sizeof(int) * 3);
	ptr++;
	while (ptr && *ptr == ' ')
		ptr++;
	i = 0;
	get(data, colors, i, ptr);
	return (colors);
}

static int	check(t_data *data, char *line, char **infos)
{
	if (ft_strcmp(infos[0], "NO\0") == 0)
		data->map->no = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "SO\0") == 0)
		data->map->so = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "WE\0") == 0)
		data->map->we = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "EA\0") == 0)
		data->map->ea = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "F\0") == 0)
		data->map->f_str = ft_strdup(line);
	else if (ft_strcmp(infos[0], "C\0") == 0)
		data->map->c_str = ft_strdup(line);
	else
	{
		free_array(infos);
		return (1);
	}
	return (0);
}

int	check_config_line(char *line, t_data *data, int total_configs)
{
	char	**infos;

	infos = ft_split(line, ' ');
	if (!infos || !infos[0] || total_configs == 6)
	{
		free_array(infos);
		return (1);
	}
	if (check(data, line, infos) == 1)
		return (1);
	free_array(infos);
	return (0);
}
