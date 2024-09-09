/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:58:12 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/09 13:43:08 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	players_init_pos(t_map *map)
{
	int	y;
	int	x;

	x = 1;
	while (x < map->rows)
	{
		y = 1;
		while (y < map->cols)
		{
			if (map->matrix[x][y] == 'P')
			{
				map->player_pos.y = y;
				map->player_pos.x = x;
			}
			if (map->matrix[x][y] == 'E')
			{
				map->exit_pos.y = y;
				map->exit_pos.x = x;
			}
			y++;
		}
		x++;
	}
}

void	flood_fill(t_map *map, int x, int y, int *ccoins)
{
	if (x < 0 || y < 0 || y >= map->cols || x >= map->rows)
		return ;
	if (map->matrix[x][y] == '1' || map->matrix[x][y] == 'V' \
			|| map->matrix[x][y] == 'E')
		return ;
	if (map->matrix[x][y] == 'C')
		(*ccoins)++;
	map->matrix[x][y] = 'V';
	flood_fill(map, x + 1, y, ccoins);
	flood_fill(map, x - 1, y, ccoins);
	flood_fill(map, x, y + 1, ccoins);
	flood_fill(map, x, y - 1, ccoins);
}

static	void	flood_exit(t_map *map, int x, int y)
{
	if (x < 0 || y < 0 || y >= map->cols || x >= map->rows)
		return ;
	if (map->matrix[x][y] == '1' || map->matrix[x][y] == 'V')
		return ;
	map->matrix[x][y] = 'V';
	flood_exit(map, x + 1, y);
	flood_exit(map, x - 1, y);
	flood_exit(map, x, y + 1);
	flood_exit(map, x, y - 1);
}

static	void	copy_map_matrix(t_map *copy_map, t_map *map)
{
	int	i;
	int	j;

	copy_map->matrix = malloc(sizeof(char *) * map->rows);
	if (!copy_map->matrix)
		handle_error("Error: Memory allocation failed\n", 30, map, NULL);
	i = 0;
	while (i < map->rows)
	{
		copy_map->matrix[i] = malloc(sizeof(char) * map->cols);
		if (!copy_map->matrix[i])
			handle_error("Error: Memory allocation failed\n", 30, map, NULL);
		j = 0;
		while (j < map->cols)
		{
			copy_map->matrix[i][j] = map->matrix[i][j];
			j++;
		}
		i++;
	}
}

/*******************CHECK_EMPTY FUNCTION*************************************/
int	validation_player(int *ccoins, t_map *map)
{
	t_map	copy_map;
	t_map	copy_map2;

	players_init_pos(map);
	copy_map.rows = map->rows;
	copy_map.cols = map->cols;
	copy_map2.rows = map->rows;
	copy_map2.cols = map->cols;
	copy_map_matrix(&copy_map, map);
	copy_map_matrix(&copy_map2, map);
	flood_fill(&copy_map, map->player_pos.x, map->player_pos.y, ccoins);
	flood_exit(&copy_map2, map->player_pos.x, map->player_pos.y);
	if (*ccoins == map->coins \
			&& (copy_map2.matrix[map->exit_pos.x][map->exit_pos.y] == 'V'))
		ft_printf("¡CCOINS Ok y Exit Ok!\n");
	else
	{
		free_map2d(&copy_map);
		free_map2d(&copy_map2);
		return (1);
	}
	free_map2d(&copy_map);
	free_map2d(&copy_map2);
	return (0);
}
