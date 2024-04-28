/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sous <ade-sous@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:37 by ade-sous          #+#    #+#             */
/*   Updated: 2024/04/20 18:34:20 by ade-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void  free_array(char **arr)
{
  int i;

  i = 0;
  while (arr[i])
  {
    free(arr[i]);
    i++;
  }
  free(arr);
}

void free_map(t_map *map)
{
  if (map->no)
	  free(map->no);
  if (map->so)
	  free(map->so);
  if (map->we)
	  free(map->we);
  if (map->ea)
	  free(map->ea);
  if (map->f_str)
    free(map->f_str);
  if (map->c_str)
    free(map->c_str);
  if (map->f)
    free(map->f);
  if (map->c)
	  free(map->c);
  if (map->map)
    free_array(map->map);
}