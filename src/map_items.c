/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_items.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:58:48 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/09 09:11:09 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	check_items(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->rows)
	{
		y = 0;
		while (y < map->cols)
		{
			if (map->matrix[x][y] != '1' && map->matrix[x][y] != 'P' \
				&& map->matrix[x][y] != 'E' && map->matrix[x][y] != 'C' \
				&& map->matrix[x][y] != '0')
			{
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	map_items(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->rows - 1)
	{
		j = 1;
		while (j < map->cols - 1)
		{
			if (map->matrix[i][j] == 'P')
				map->player++;
			else if (map->matrix[i][j] == 'C')
				map->coins++;
			else if (map->matrix[i][j] == 'E')
				map->exit++;
			j++;
		}
		i++;
	}
}

/************************VALIDATION MAIN **************************/
int	items_errors(t_map *map)
{
	if (check_items(map) == 1)
	{
		printf("entramos en map_items() if (check_items)\n");
		return (1);
	}
	map_items(map);
	if (map->coins < 1 || map->exit != 1 || map->player != 1)
	{
		printf("error de mas de un items\n");
		return (1);
	}
	return (0);
}
