/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:47:31 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:46 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

int	pm_read_header(int fd, t_map *map)
{
	char	*line;
	int		len;

	line = read_line(fd, &len);
	if (!line)
		return (-1);
	if (parse_header_line(line, map) != 0)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

int	pm_alloc_grid(t_map *map)
{
	map->grid = (char **)malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (-1);
	map->cols = -1;
	return (0);
}

int	pm_check_line(t_map *map, char *line, int len)
{
	int	j;

	if (map->cols == -1)
	{
		map->cols = len;
		if (map->cols <= 0)
			return (-1);
	}
	else if (len != map->cols)
		return (-1);
	j = 0;
	while (j < len)
	{
		if (line[j] != map->empty && line[j] != map->obstacle)
			return (-1);
		j++;
	}
	return (0);
}

int	pm_load_rows(int fd, t_map *map)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	while (i < map->rows)
	{
		line = read_line(fd, &len);
		if (!line)
			return (-1);
		if (pm_check_line(map, line, len) != 0)
		{
			free(line);
			return (-1);
		}
		map->grid[i] = line;
		i++;
	}
	return (0);
}

int	parse_map(int fd, t_map *map)
{
	char	extra;

	map->grid = NULL;
	if (pm_read_header(fd, map) != 0)
		return (-1);
	if (pm_alloc_grid(map) != 0)
		return (-1);
	if (pm_load_rows(fd, map) != 0)
	{
		free_map(map);
		return (-1);
	}
	if (read(fd, &extra, 1) > 0)
	{
		free_map(map);
		return (-1);
	}
	return (0);
}
