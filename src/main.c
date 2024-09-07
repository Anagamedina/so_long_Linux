/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:20:29 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/07 15:15:22 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_game(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		ccoins;

	game = NULL;
	ccoins = 0;
	if (argc != 2)
		handle_exit(ERROR_INVALID_ARG, 26);
	else
	{
		game = init_game();
		if (game != NULL)
		{
			map_format_border_check(argv[1], game->map);
			map_items(game->map);
			validation_player(&ccoins, game->map);
			init_sprite(game);
			mlx_key_hook(game->win_ptr, handle_input, game);
			mlx_hook(game->win_ptr, 17, 0, close_window, game);
			mlx_loop(game->mlx_ptr);
		}
		else
		{
			free_game(game);

		}
		// free_game(game);
	}
	return (0);
}
