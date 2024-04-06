#include "../includes/cub3d.h"

// int check_config_line(char *line)
// {
//     if (ft_strcmpr(line, ""))
// }

int	read_map(char *filename)
{
    //int     is_config_line;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		printf("Failed to open and read file.\n");


	while (1)
	{
		line = get_next_line(fd);

        //if (!is_config_line)
		printf("%s", line);
		if (!line)
			break ;
	}
	printf("\n");
	return (0);
}