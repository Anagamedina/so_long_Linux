/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:20:29 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/09 13:32:55 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc != 2)
		handle_exit(ERROR_INVALID_ARG, 26);
	else
	{
		game = init_game();
		if (game != NULL)
		{
			check_empty(argv, game, 0);
			init_sprite(game);
			mlx_key_hook(game->win_ptr, handle_input, game);
			mlx_hook(game->win_ptr, 17, 0, close_window, game);
			mlx_loop(game->mlx_ptr);
		}
		else
			free_game(game);
	}
	return (0);
}
