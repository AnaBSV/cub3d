/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:34:39 by ade-sous          #+#    #+#             */
/*   Updated: 2024/04/06 15:36:00 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_window(int code, t_data *data)
{
	(void)code;
	exit_cub("Programa encerrado!\n", data);
	return(0);
}

int	pressed_key(int key, t_data *data)
{
	if (key == 65307)
		exit_cub("Programa Encerrado!", data);
	if (key == 119)
		move_player(data, 1, "vertical");
	if (key == 115)
		move_player(data, -1, "vertical");
	if (key == 65361)
		rotate(data, -1);
	if (key == 65363)
		rotate(data, 1);
	if (key == 100)
		move_player(data, 1, "horizontal");
	if (key == 97)
		move_player(data, -1, "horizontal");
	return (0);
}