#include "../includes/cub3d.h"

int	get_map(char *filename, t_data *data)
{
	int		fd;
	char	*line;
    int     i = 0;
    int     map_index = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_cub("Failed to open and read file.\n", data);
    data->map->map = malloc(sizeof(char *) * (data->map->total_lines) + 1);
	while (map_index < data->map->total_lines)
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
        data->map->map[map_index] = ft_strdup(line);
        free(line);
        map_index++;
        i++;
	}
    data->map->map[map_index] = '\0';
	return (0);
}