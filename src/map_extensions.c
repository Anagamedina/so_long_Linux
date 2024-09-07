/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:25:47 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/07 19:37:06 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	validate_path(char *argv)
{
	char	*file_extension;
	int		len_file_extension;
	int		len_argv;
	int		i;

	file_extension = ".ber";
	len_file_extension = ft_strlen (file_extension);
	len_argv = ft_strlen(argv);
	i = len_file_extension;
	while (i >= 0)
	{
		if (argv[len_argv] != file_extension[i])
			return (1);
		i--;
		len_argv--;
	}
	return (0);
}

static int	check_first_and_last_line(t_map *map)
{
	int	j;

	j = 0;
	while (map->matrix[0][j] != '\0')
	{
		if (map->matrix[0][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (map->matrix[map->rows - 1][j] != '\0')
	{
		if (map->matrix[map->rows - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

static int	check_laterals_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i][0] != '1' \
			|| map->matrix[i][map->cols - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i][map->cols - 1] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/************************VALIDATION MAIN **************************/

int	map_format_border_check(char *path, t_map *map)
{
	if (validate_path(path) == 0)
	{
		printf("file is valid\n");
		if (read_map(path, map) == 1)
		{
			printf("aliberamos y exit de 1 linia vacia\n");
			return (1);
		}
		if (check_first_and_last_line(map) == 1 || check_laterals_map(map) == 1)
		{
			printf("entramos en error walls para aliberar y exit\n");
//			free_map2d(map);
			return (1);
		}
	}
	else
	{
		printf("mapa correcto entramos\n");
		return (0);
	}
	return (0);
}
