/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:35:57 by ade-sous          #+#    #+#             */
/*   Updated: 2024/04/20 21:36:20 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"


char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
	{
		free(s);
		return (0);
	}
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
	}
	if ((unsigned char)c == 0)
		return (s + i);
	return (0);
}