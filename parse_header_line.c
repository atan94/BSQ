/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:20:28 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:44 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <limits.h>

int	parse_characters(char *header, t_map *map, int len)
{
	map->fill = header[len - 1];
	map->obstacle = header[len - 2];
	map->empty = header[len - 3];
	if (map->empty == map->obstacle || map->empty == map->fill
		|| map->obstacle == map->fill)
		return (-1);
	if (map->empty >= '0' && map->empty <= '9')
		return (-1);
	return (0);
}

long	parse_total_lines(char *header, int len)
{
	int		i;
	long	total_lines;

	i = 0;
	total_lines = 0;
	while (i < len)
	{
		if (header[i] < '0' || header[i] > '9')
			return (-1);
		total_lines = total_lines * 10 + (header[i] - '0');
		if (total_lines > INT_MAX)
			return (-1);
		i++;
	}
	if (total_lines <= 0)
		return (-1);
	return (total_lines);
}

int	parse_header_line(char *header, t_map *map)
{
	int		len;
	long	total_lines;
	int		numlen;

	len = 0;
	while (header[len])
	{
		if (header[len] < ' ' || header[len] > '~')
			return (-1);
		len++;
	}
	if (len < 4)
		return (-1);
	if (parse_characters(header, map, len) == -1)
		return (-1);
	numlen = len - 3;
	if (numlen <= 0)
		return (-1);
	total_lines = parse_total_lines(header, numlen);
	if (total_lines < 1)
		return (-1);
	map->rows = (int)total_lines;
	return (0);
}
