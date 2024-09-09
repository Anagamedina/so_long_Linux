/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:18:55 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/09 13:49:19 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	char	*allocate_map1d(size_t size)
{
	char	*map1d;

	map1d = (char *)malloc(size + 1);
	if (!map1d)
		handle_exit(ERROR_MEMORY, 35);
	return (map1d);
}

static	int	count_file_size(char *path)
{
	int		fd;
	ssize_t	bytes_read;
	char	buffer;
	int		size;

	size = 0;
	fd = ft_open_map(path);
	bytes_read = read(fd, &buffer, 1);
	if (bytes_read == 0)
	{
		close(fd);
		return (1);
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &buffer, 1);
		size++;
	}
	close(fd);
	return (size);
}

static	char	*read_file_content(char *path, int size)
{
	int		fd;
	char	*map1d;
	ssize_t	bytes_read;

	map1d = allocate_map1d(size);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(map1d);
		handle_exit(ERROR_OPEN_FILE, 32);
	}
	bytes_read = read(fd, map1d, size);
	if (bytes_read < 0)
	{
		free(map1d);
		close(fd);
		handle_exit(ERROR_OPEN_FILE, 32);
	}
	map1d[size] = '\0';
	close(fd);
	return (map1d);
}

/************************MAP EXTENSION FUNCTION **************************/

int	read_map(char *path, t_map *map)
{
	int		file_size;
	char	*map1d;

	file_size = count_file_size(path);
	if (file_size <= 2)
		return (1);
	map1d = read_file_content(path, file_size);
	if (map1d == NULL)
		return (1);
	map->matrix = ft_split(map1d, '\n');
	free(map1d);
	if (map->matrix == NULL)
		handle_exit(ERROR_MEMORY, 35);
	if (set_map_dimensions(map) == 1 || check_map_dimensions(map) == 1)
		return (1);
	return (0);
}
