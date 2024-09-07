/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:22:21 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/05 20:53:16 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_game *game)
{
	if (game && game->mlx_ptr)
	{
		if (game->wall.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
		if (game->floor.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
		if (game->coin.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->coin.xpm_ptr);
		if (game->exit_closed.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
		if (game->player_front.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
		if (game->player_left.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
		if (game->player_right.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
		if (game->player_back.xpm_ptr)
			mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
	}
}

void	ft_close_game(t_game *game)
{
	if (game)
	{
		free_images(game);
		if (game->map)
		{
			free_map2d(game->map);
			free(game->map);
		}
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		free(game);
	}
	exit(0);
}

void	ft_victory(t_game *game)
{
	ft_printf("Congratulations! You have won the game in %d moves!\n", \
		game->movements);
	ft_close_game(game);
}
