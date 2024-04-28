/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:21:49 by ade-sous          #+#    #+#             */
/*   Updated: 2024/04/20 21:50:10 by ade-sous         ###   ########.fr       */
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
// size_t	ft_strlen(char *s);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strchr(char *s, int c);

#endif
