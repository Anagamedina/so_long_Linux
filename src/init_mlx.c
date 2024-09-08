/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:21:53 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/08 18:54:37 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf("Error initializing mlx.\n");
		free(game->mlx_ptr);
		exit (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map->cols * TILE_SIZE, \
		game->map->rows * TILE_SIZE, "Welcome so_long's Ana");
	if (game->win_ptr == NULL)
	{
		ft_printf("Error creating window.\n");
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		exit(1);
	}
}

void	new_image(t_game *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{
		ft_printf("Error: Couldn't find a sprite at path: %s\n", path);
		exit (1);
	}
}

/*****************MAIN FUNCTION*******************/

void	init_sprite(t_game *game)
{
	init_mlx(game);
	new_image(game, &game->player_front.xpm_ptr, PLAYER_FRONT_XPM);
	new_image(game, &game->player_back.xpm_ptr, PLAYER_BACK_XPM);
	new_image(game, &game->player_left.xpm_ptr, PLAYER_LEFT_XPM);
	new_image(game, &game->player_right.xpm_ptr, PLAYER_RIGHT_XPM);
	new_image(game, &game->exit_closed.xpm_ptr, OPEN_EXIT_XPM);
	new_image(game, &game->coin.xpm_ptr, COIN_XPM);
	new_image(game, &game->floor.xpm_ptr, FLOOR_XPM);
	new_image(game, &game->wall.xpm_ptr, WALL_XPM);
	identify_images(game, 0, 0);
}
