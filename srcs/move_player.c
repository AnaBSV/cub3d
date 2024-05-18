#include "../includes/cub3d.h"

void	move_player(t_data *data, int n, char *dir)
{
	double	y_temp;
	double	x_temp;

    if (!ft_strcmp(dir, "vertical"))
    {
        y_temp = data->player_dir_y * n * MOVE_SPEED * 2 + data->player_y;
        x_temp = data->player_dir_x * n * MOVE_SPEED * 2 + data->player_x;
        if (data->map->map[(int) y_temp][(int) x_temp] != '1')
        {
            data->player_y = data->player_dir_y * n * MOVE_SPEED + data->player_y;
            data->player_x = data->player_dir_x * n * MOVE_SPEED + data->player_x;
            //printf("\n>>>entrou aqui %f %f\n", data->player_y, data->player_x);
        }
    }
    else if (!ft_strcmp(dir, "horizontal"))
    {
        y_temp = (data->player_plane_y * MOVE_SPEED) * n;
        x_temp = (data->player_plane_x * MOVE_SPEED) * n;
        if (data->map->map[(int)(data->player_y + y_temp)][\
        (int)(data->player_x + x_temp)] != '1')
            data->player_x += x_temp;
        if (data->map->map[(int)(data->player_y + y_temp)][\
        (int)(data->player_x + x_temp)] != '1')
        data->player_y += y_temp;
    }
	
}

void	rotate(t_data *data, int n)
{
	double	old_dir;
	double	old_plan;

	old_dir = data->player_dir_x;
	old_plan = data->player_plane_x;
	data->player_dir_x = data->player_dir_x * cos(ROT_SPEED * n) - \
	data->player_dir_y * sin(ROT_SPEED * n);
	data->player_dir_y = old_dir * sin(ROT_SPEED * n) + \
	data->player_dir_y * cos(ROT_SPEED * n);
	data->player_plane_x = data->player_plane_x * cos(ROT_SPEED * n) - \
	data->player_plane_y * sin(ROT_SPEED * n);
	data->player_plane_y = old_plan * sin(ROT_SPEED * n) + \
	data->player_plane_y * cos(ROT_SPEED * n);
}
