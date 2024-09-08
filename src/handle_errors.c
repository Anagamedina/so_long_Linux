/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:22:06 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/08 19:42:13 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map2d(t_map *map)
{
	int	i;

	if (map != NULL)
	{
		if (map->matrix != NULL)
		{
			i = 0;
			while (i < map->rows && map->matrix[i] != NULL)
			{
				free(map->matrix[i]);
				i++;
			}
			free(map->matrix);
		}
	}
}

void	handle_error(char *str, int size, t_map *map, t_game *game)
{
	if (str && size > 0)
		write(2, str, size);
	if (map != NULL)
	{
		free_map2d(map);
	}
	if (game != NULL)
		free_game(game);
	exit(EXIT_FAILURE);
}

void	handle_exit(char *str, int size)
{
	write(2, str, size);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map != NULL)
			free_map2d(game->map);
		free(game);
	}
}

void	check_empty(char **argv, t_game *game)
{
	if (map_format_border_check(argv[1], game->map) == 1)
	{
		free_map2d(game->map);
		free(game->map);
		free(game);
		handle_exit(ERROR_INVALID_MAP, 23);
	}
	else if (items_errors(game->map) == 1)
	{
		free_map2d(game->map);
		free(game->map);
		free(game);
		handle_exit(ERROR_ITEMS, 32);
	}
	else
		return ;
}