/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:47:10 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/23 18:15:40 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

void	exit_cub(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (2, &str[i], 1);
		i++;
	}
	free_map (data->map);
	exit (1);
}

int	is_end_of_line(char *line, int col)
{
	int	i;

	i = col + 1;
	while (line[i] == ' ')
	{
		i++;
	}
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	else
		return (1);
}

int	is_valid_map(char *str, char *ext)
{
	int	len;
	int	i;

	len = ft_strlen(str) - 1;
	i = 3;
	while (i >= 0)
	{
		if (str[len] != ext[i])
			return (1);
		i--;
		len--;
	}
	return (0);
}
