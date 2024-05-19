/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopes <vlopes@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:31:10 by vlopes            #+#    #+#             */
/*   Updated: 2024/05/18 20:54:54 by vlopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l_s1;
	size_t	l_s2;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = (malloc(sizeof(char) * (l_s1 + l_s2 + 1)));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, (char *)s1, l_s1 + 1);
	ft_strlcpy(&str[l_s1], (char *)s2, l_s2 + 1);
	free(s1);
	return (str);
}
