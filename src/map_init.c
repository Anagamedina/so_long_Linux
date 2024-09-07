/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:18:55 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/07 18:12:48 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_exit(ERROR_OPEN_FILE, 32);
	return (fd);
}

static char *allocate_map1d(size_t size)
{
    char *map1d;

    map1d = (char *)malloc(size + 1);
    if (!map1d)
    {
        handle_exit(ERROR_MEMORY, 35);
    }
    return map1d;
}

static char	*read_file(char *path, int i)
{
	int		fd;
	char	*map1d;
	char	buffer;
	ssize_t	bytes_read;

	fd = ft_open_map(path);
	bytes_read = read(fd, &buffer, 1);
	if (bytes_read == 0)
	{
		ft_printf("archivo vacio\n");
		close (fd);
		handle_exit(ERROR_OPEN_FILE, 32);
	}
	while (bytes_read > 0 && ++i)
		bytes_read = read(fd, &buffer, 1);
	if (i <= 2 && bytes_read == 0)
	{
		printf("archivo con 1 linia espacio y nulo\n");
		return (NULL);
	}
	close (fd);
	map1d = allocate_map1d(i);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(map1d);
		handle_exit(ERROR_OPEN_FILE, 32);
	}
	bytes_read = read(fd, map1d, i);
	if (bytes_read < 0)
	{
		free(map1d);
		close(fd);
		handle_exit(ERROR_OPEN_FILE, 32);
	}
	map1d[i] = '\0';
	close(fd);
	return (map1d);
}

static void	set_map_dimensions(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrix[i] != NULL)
		i++;
	map->rows = i;
	if (map->matrix[0] == NULL)
		handle_error(ERROR_INVALID_MAP, 30, map, NULL);
	map->cols = (int)ft_strlen(map->matrix[0]);
}

static void	check_map_dimensions(t_map *map)
{
	int	i;
	int	line;

	i = 0;
	while (map->matrix[i] != NULL)
	{
		line = (int)ft_strlen(map->matrix[i]);
		if (map->cols != line)
			handle_error(ERROR_INVALID_MAP, 30, map, NULL);
		i++;
	}
}

/************************MAIN FUNCTION **************************/
int	read_map(char *path, t_map *map)
{
	char	*map1d;

	map1d = read_file(path, 0);
	if (map1d == NULL)
	{
		free(map1d);
		return (1);
	}
	map->matrix = ft_split(map1d, '\n');
	free(map1d);
	if (map->matrix == NULL)
		handle_exit(ERROR_MEMORY, 35);
	set_map_dimensions(map);
	check_map_dimensions(map);
	return (0);
}
