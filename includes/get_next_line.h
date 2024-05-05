/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:21:49 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/04 16:11:24 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#include "./libft.h"

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 2
#endif

char	*get_next_line(int fd);
//char	*ft_strjoin(char *s1, char *s2);
int		endof_line(char *backup);
char	*generate_of_eof(const char *backup);
char	*ft_strdup(const char *s);

#endif
