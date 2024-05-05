/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:47:10 by ade-sous          #+#    #+#             */
/*   Updated: 2024/05/04 15:37:56 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

int count_char(char *str, char c)
{
  int i;
  int count;

  i = 0;

  while(str[i])
  {
    if (str[i] == c)
      count++;
    i++;
  }
  return (count);
}

int is_empty_line(char *str)
{
  int i;

  i = 0;

  while(str[i] == ' ')
    i++;
  if(str[i] == '\n')
    i++;
  if(str[i] == '\0')
    return(0);
  else
    return(1);
}

void exit_cub(char *str, t_data *data)
{
  int i = 0;

  while (str[i])
  {
    write(2, &str[i], 1);
    i++;
  }
  free_map(data->map);
  exit(1);
}