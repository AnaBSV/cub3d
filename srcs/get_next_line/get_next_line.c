/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:51:28 by vlopes            #+#    #+#             */
/*   Updated: 2024/04/06 18:09:12 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static char	*ft_fuction(char *rec)
{
	char	*other;
	int		i;

	i = 0;
	if (!rec[i])
		return (0);
	while (rec[i] && rec[i] != 10)
		i++;
	other = malloc((i + 2) * sizeof(char));
	if (!other)
		return (0);
	i = 0;
	while (rec[i] && rec[i] != 10)
	{
		other[i] = rec[i];
		i++;
	}
	if (rec[i] == 10)
		other[i++] = 10;
	other[i] = 0;
	return (other);
}

static char	*ft_cut(char *rec)
{
	char	*cut;
	int		i;
	int		m;

	i = 0;
	while (rec[i] != 10 && rec[i])
		i++;
	if (!rec[i])
	{
		free(rec);
		return (0);
	}
	m = 0;
	cut = malloc((ft_strlen(rec) - i + 1) * sizeof(char));
	if (!cut)
		return (0);
	i++;
	while (rec[i])
		cut[m++] = rec[i++];
	cut[m] = 0;
	free(rec);
	return (cut);
}

static char	*rec_function(int fd, char *rec)
{
	char	*util;
	int		i;

	i = 1;
	util = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!util)
		return (0);
	while (!ft_strchr(rec, 10) && i != 0)
	{
		i = read(fd, util, BUFFER_SIZE);
		if (i < 0)
		{
			free(util);
			return (0);
		}
		util[i] = 0;
		if (!rec)
		{
			rec = malloc(1 * sizeof(char));
			*rec = 0;
		}
		rec = ft_strjoin(rec, util);
	}
	free(util);
	return (rec);
}

char	*get_next_line(int fd)
{
	static char	*rec;
	char		*other;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	rec = rec_function(fd, rec);
	if (!rec)
		return (0);
	other = ft_fuction(rec);
	rec = ft_cut(rec);
	return (other);
}
