#include "../includes/cub3d.h"

void remove_texture_nl(char *str) {
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] ='\0';
			break;
		}
		i++;
	}

}

int array_len(char **arr)
{
	int i = 0;

	while (arr[i])
		i++;
	return (i);
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
	while (ptr && *ptr != '\0' && i < 3)
	{
		colors[i] = ft_atoi(ptr);

		if (colors[i] < 0 || colors[i] >= 255)
			exit_cub("Invalid Color Info\n", data);
		
		ptr = ft_strchr(ptr, ',');
		if (ptr == NULL)
			break;
		ptr++;
		while (ptr && *ptr == ' ')
    		ptr++;
		
		i++;
	}
	return (colors);
}


int check_config_line(char *line, t_data *data, int total_configs)
{
  char **infos;

	infos = ft_split(line, ' ');
	if (!infos || !infos[0] || total_configs == 6)
	{
		free_array(infos);
		return (1);
	}
	//printf("infos[0]: %s\n", infos[0]);
	
	if (ft_strcmp(infos[0], "NO\0") == 0)
		data->map->no = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "SO\0") == 0)
		data->map->so = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "WE\0") == 0)
		data->map->we = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "EA\0") == 0)
		data->map->ea = ft_strdup(infos[1]);
	else if (ft_strcmp(infos[0], "F\0") == 0)
		data->map->f_str = ft_strdup(line);//get_color_info(line, 'F', data, infos);
	else if (ft_strcmp(infos[0], "C\0") == 0)
		data->map->c_str = ft_strdup(line);//get_color_info(line, 'C', data, infos);
	else
	{
		free_array(infos);
		return (1);
	}


	free_array(infos);
	return(0);
}

int	read_map_configs(char *filename, t_data *data)
{
	int		is_config_line;
	int		fd;
	char	*line;
	int		total_configs;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		exit_cub("Failed to open and read file.\n", data);
	}

	total_configs = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);

		if (!line)
			break ;
		else if (!is_empty_line(line) || total_configs < 0)
		{
			i++;
			free(line);
			continue;
		}

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
		else if(total_configs <= 5 && is_config_line)
		{
			free(line);
			exit_cub("Erro nas Configurações A\n", data);
		}
		free(line);
		i++;
	}

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