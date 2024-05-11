/*
#include "../includes/cub3d.h"

void	ver_line(int x, int y1, int y2, int color, t_data *data)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		y++;
	}
}

void	init_player(t_data *data)
{
    t_player	player;

    player.posx = data->map->px * TILE + TILE / 2;
    player.posy = data->map->py * TILE + TILE / 2;

}


void	init(t_data *data)
{
	data->name = "Cub3d";
	data->map->map_begin_line = -1;
	data->map->total_lines = 0;
	data->map->width = 0;
	
	data->map->no = NULL;
	data->map->so = NULL;
	data->map->ea = NULL;
	data->map->we = NULL;
	data->map->f = NULL;
	data->map->c = NULL;
	data->map->f_str = NULL;
	data->map->c_str = NULL;
	data->map->map = NULL;

	data->map->old_time = 0;
	data->map->time = 0;
}

void	game_loop(t_data *data)
{
    int		i;
	double	ray_d_x;
	double	ray_d_y;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	perpwalldist;
	double	color;
	double camy;
	double camx;
	double old_time;
	double time;

    i = 0;
	hit = 0;
	old_time = 0;
	time = 0;
    while (i < WIDTH)
	{
		camx = 2 * i / (double)WIDTH - 1;
		ray_d_x = data->map->dirx + data->map->planx * camx;
		ray_d_y = data->map->diry + data->map->plany * camy;
		mapx = data->map->posx;
		mapy = data->map->posy;
		if (ray_d_x == 0)
			deltadistx = pow(1, 30);
		else
			deltadistx = abs((int)(1/ray_d_x));
		if (ray_d_y == 0)
			deltadisty = pow(1, 30);
		else
			deltadisty = abs((int)(1/ray_d_y));
		i++;
	
		if (ray_d_x < 0)
		{
			stepx = -1;
			sidedistx = (data->map->posx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - data->map->posx) * deltadistx;
		}
		if (ray_d_y < 0)
		{
			stepy = -1;
			sidedisty = (data->map->posy - mapy) * deltadisty;
		}
		else
		{
			stepx = 1;
			sidedisty = (mapy + 1.0 - data->map->posy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (data->map->map[mapx][mapy] > 0)
				hit = 1;
		}
		if (side == 0)
			perpwalldist = sidedistx - deltadistx;
		else
			perpwalldist = sidedisty - deltadisty;
		lineheight = (int)(HEIGHT / perpwalldist);
		drawstart = -lineheight / HEIGHT + HEIGHT / 2;
		drawend = lineheight / HEIGHT + HEIGHT / 2;
		if (drawstart < 0)
			drawstart = 0;
		if (drawend >= HEIGHT)
			drawend = HEIGHT - 1;
		if (data->map->map[mapx][mapy] == '1')
			color = BLUE;
		if (side == 1)
			color = color / 2;
		ver_line(i, drawstart, drawend, color, data);
	}

	old_time = time;
    time = getTicks();
    double frameTime = (time - old_time) / 1000.0;
    //printf(1.0 / frameTime);
    redraw();
    cls();

	double moveSpeed = frameTime * 5.0;
    double rotSpeed = frameTime * 3.0;

	readKeys();
	

}
*/