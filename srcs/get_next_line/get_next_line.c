/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:51:28 by vlopes            #+#    #+#             */
/*   Updated: 2024/05/18 20:52:29 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*save_and_clear(char *backup)
{
	int		i;
	char	*new_backup;

	i = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	if (backup[i] == '\n')
		i++;
	new_backup = ft_strdup(&backup[i]);
	free(backup);
	return (new_backup);
}

char	*generate_of_eof(const char *backup)
{
	char	*line;
	int		len;

	len = -1;
	while (backup[++len])
	{
		if (backup[len] == '\n')
			break ;
	}
	line = malloc(sizeof(char) * (len + 2));
	return (line);
}

char	*extract_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup[i])
		return (NULL);
	line = generate_of_eof(backup);
	if (!line)
		return (NULL);
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_and_add(char *backup, int bytes_read, int fd)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!endof_line(backup) && bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*str;
	int			bytes_read;

	bytes_read = 1;
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_and_add(backup, bytes_read, fd);
	if (!backup)
		return (NULL);
	str = extract_line(backup);
	backup = save_and_clear(backup);
	return (str);
}
