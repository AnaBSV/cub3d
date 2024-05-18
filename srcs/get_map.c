#include "../includes/cub3d.h"
static char *ft_strdup_map(char *str)
{
	int len = 0;
	int i = 0;

	while(is_end_of_line(str, len) == 1)
		len++;

	char *copy = malloc(sizeof(char) * (len + 1));

	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';

	return (copy);
}

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
        data->map->map[map_index] = ft_strdup_map(line);
		free(line);
        map_index++;
        i++;
	}
    data->map->map[map_index] = '\0';
	return (0);
}

void	check_map(char **map, t_data *data)
{
	int	i;
	int	j;

	int player;

	i = 0;
	player = 0;
	printf("2\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' ' || map[i][j] == '\n')
				j++;
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				printf("x: %d | y: %d\n", i, j);
				data->player_x = (double)j + 0.5;
				data->player_y = (double)i + 0.5;
				init_player(data, i, j, map);
				player++;
				j++;
			}
			else{
				printf("map[%d][%d]: %c\n", i, j, map[i][j]);
				exit_cub("Invalid map: unknown char\n", data);
			}
		}
		i++;
	}
	if (player != 1)
		exit_cub("Invalid map: Just one player is accepted\n", data);
}
