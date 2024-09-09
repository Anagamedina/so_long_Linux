/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:49:47 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/09 13:47:01 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_exit(ERROR_OPEN_FILE, 32);
	return (fd);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_game(game);
	exit(0);
}

int	set_map_dimensions(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrix[i] != NULL)
		i++;
	map->rows = i;
	if (map->matrix[0] == NULL)
		return (1);
	map->cols = (int)ft_strlen(map->matrix[0]);
	return (0);
}

int	check_map_dimensions(t_map *map)
{
	int	i;
	int	line;

	i = 0;
	while (map->matrix[i] != NULL)
	{
		line = (int)ft_strlen(map->matrix[i]);
		if (map->cols != line)
			return (1);
		i++;
	}
	return (0);
}
