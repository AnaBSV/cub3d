/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:15:16 by vlopes            #+#    #+#             */
/*   Updated: 2024/04/06 18:00:48 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isalnum(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('a' <= c && c <= 'z')
		return (1);
	else
		return (0);
}
