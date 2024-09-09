/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:26:31 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/09 10:01:13 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <strings.h>
# include <stdlib.h>
# include <fcntl.h>
# include "macros.h"

/********Estructura para posiciones en 2D*****/
typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**matrix;
	int			rows;
	int			cols;
	int			coins;
	int			exit;
	int			player;
	t_position	player_pos;
	t_position	exit_pos;
}	t_map;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				movements;
	int				player_sprite;
	t_map			*map;
	t_image			wall;
	t_image			floor;
	t_image			coin;
	t_image			exit_closed;
	t_image			player_front;
	t_image			player_left;
	t_image			player_right;
	t_image			player_back;
}			t_game;

t_game	*init_game(void);
t_map	*init_map(void);
int		map_format_border_check(char *path, t_map *map);
void	map_items(t_map *map);
int		read_map(char *path, t_map *map);
// void	read_map(char *path, t_map *map);
void	validation_player(int *ccoins, t_map *map);
void	init_mlx(t_game *game);
void	check_empty(char **argv, t_game *game);
int		items_errors(t_map *map);
int		ft_open_map(char *path);
void	check_empty(char **argv, t_game *game);
int		close_window(t_game *game);
int		set_map_dimensions(t_map *map);
int		check_map_dimensions(t_map *map);

/********HANDLE ERROR AND FREE ****/
void	handle_error(char *str, int size, t_map *map, t_game *game);
void	handle_exit(char *str, int size);
void	free_game(t_game *game);
void	free_map2d(t_map *map);

/********SPRITES****/
void	new_image(t_game *game, void **image, char *path);
void	init_sprite(t_game *game);
void	identify_images(t_game *game, int i, int j);
int		handle_input(int keysym, t_game *game);

/********PRINT DATA****/
void	print_map(t_map *map);
void	free_images(t_game *game);
void	ft_close_game(t_game *game);
void	ft_victory(t_game *game);

#endif // GAME_H