/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:44:00 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:35 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_square(t_map *map, int size, int row, int col)
{
	int	r;
	int	c;
	int	si;
	int	sj;

	if (size <= 0)
		return ;
	si = row - size + 1;
	sj = col - size + 1;
	r = 0;
	while (r < size)
	{
		c = 0;
		while (c < size)
		{
			map->grid[si + r][sj + c] = map->fill;
			c = c + 1;
		}
		r = r + 1;
	}
}
