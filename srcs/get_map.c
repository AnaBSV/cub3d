#include "../includes/cub3d.h"

int	get_map(char *filename, t_data *data)
{
	int		fd;
	char	*line;
    int     i = 0;
    int     map_index = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		exit_cub("Failed to open and read file.\n", data);
	}

    data->map->map = malloc(sizeof(char *) * data->map->total_lines);
	while (1)
	{
		line = get_next_line(fd);
    
		if (!line)
			break ;
        if (i < data->map->map_begin_line)
        {
            i++;
            free(line);
            continue;
        }
        //printf("%s", line);
        data->map->map[map_index] = ft_strdup(line);
        free(line);
        map_index++;
        i++;
	}

	return (0);
}