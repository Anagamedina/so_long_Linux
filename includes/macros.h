/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:42:16 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/05 18:00:21 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*--------------------Error and free------------------*/
# define ERROR_INVALID_MAP "error\nInvalid map file\n"
# define ERROR_MEMORY_ALLOCATION "error: Memory allocation failed\n"
# define ERROR_INVALID_ARG "Error\nInvalid argument.\n"
# define ERROR_WALLS "Error\nInvalid walls in map.\n"
# define ERROR_COINS_EXIT "Error\nInvalid game\n"
# define ERROR_ITEMS "Error\nInvalid items\n"

/*--------------------Error and exit------------------*/
# define ERROR_OPEN_FILE "Error\nFailure to open arg-file.\n"
# define ERROR_MEMORY "Error\nMemory allocation failure.\n"

/*-------------------- ITEMS ASSIGN ------------------*/
# define WALL '1'
# define FLOOR '0'
# define COINS 'C'
# define EXIT 'E'
# define PLAYER 'P'

// Direcciones del jugador
# define LEFT 0
# define RIGHT 1
# define UP 2
# define DOWN 3
# define BACK 2
# define FRONT 3

/*-------------------- SIZE OF SPRITE ------------------*/
# define TILE_SIZE 32

/*-------------------- XPM PATHS -----------------------*/

# define PLAYER_FRONT_XPM "textures/player_front.xpm"
# define PLAYER_LEFT_XPM "textures/player_left.xpm"
# define PLAYER_RIGHT_XPM "textures/player_right.xpm"
# define PLAYER_BACK_XPM "textures/player_back.xpm"
# define COIN_XPM "textures/coin.xpm"
# define FLOOR_XPM "textures/floor.xpm"
# define WALL_XPM "textures/wall.xpm"
# define EXIT_CLOSED_XPM "textures/exit-closed.xpm"
# define OPEN_EXIT_XPM "textures/open-exit.xpm"

/*-------------------- KEYS EVENTS ------------------*/
# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_Q      113

# define KEY_ESC    65307
# define KEY_UP     65362
# define KEY_DOWN   65364
# define KEY_LEFT   65361
# define KEY_RIGHT  65363

#endif /* MACROS_H */
