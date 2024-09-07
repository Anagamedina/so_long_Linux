/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:21:00 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/05 20:23:12 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->matrix = NULL;
	map->rows = 0;
	map->cols = 0;
	map->coins = 0;
	map->exit = 0;
	map->player = 0;
	map->player_pos.x = -1;
	map->player_pos.y = -1;
	map->exit_pos.x = -1;
	map->exit_pos.y = -1;
	return (map);
}

/************************VALIDATION MAIN **************************/
t_game	*init_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = init_map();
	if (!game->map)
	{
		free(game);
		return (NULL);
	}
	game->movements = 0;
	game->player_sprite = 0;
	game->wall.xpm_ptr = NULL;
	game->floor.xpm_ptr = NULL;
	game->coin.xpm_ptr = NULL;
	game->exit_closed.xpm_ptr = NULL;
	game->player_front.xpm_ptr = NULL;
	game->player_left.xpm_ptr = NULL;
	game->player_right.xpm_ptr = NULL;
	game->player_back.xpm_ptr = NULL;
	return (game);
}
