/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:19:28 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/05 20:24:42 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x, y);
}

void	render_player(t_game *game, int x, int y)
{
	if (game->player_sprite == BACK)
		put_image(game, game->player_back.xpm_ptr, x, y);
	else if (game->player_sprite == FRONT)
		put_image(game, game->player_front.xpm_ptr, x, y);
	else if (game->player_sprite == LEFT)
		put_image(game, game->player_left.xpm_ptr, x, y);
	else if (game->player_sprite == RIGHT)
		put_image(game, game->player_right.xpm_ptr, x, y);
}

static void	put_element_image(t_game *game, int x, int y, char element)
{
	if (element == WALL)
		put_image(game, game->wall.xpm_ptr, x, y);
	else if (element == FLOOR)
		put_image(game, game->floor.xpm_ptr, x, y);
	else if (element == EXIT)
		put_image(game, game->exit_closed.xpm_ptr, x, y);
	else if (element == PLAYER)
	{
		put_image(game, game->player_front.xpm_ptr, x, y);
		render_player(game, x, y);
	}
	else if (element == COINS)
		put_image(game, game->coin.xpm_ptr, x, y);
}

void	identify_images(t_game *game, int i, int j)
{
	int	x;
	int	y;

	while (i < game->map->rows)
	{
		j = 0;
		while (j < game->map->cols)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			put_element_image(game, x, y, game->map->matrix[i][j]);
			j++;
		}
		i++;
	}
}
