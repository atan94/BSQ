/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:11:26 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:54 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver_int.h"
#include <stdlib.h>

void	solve_map(t_map *map)
{
	int		*dp;
	t_best	best;
	int		i;

	if (!map || map->rows <= 0 || map->cols <= 0)
		return ;
	dp = (int *)malloc(sizeof(int) * map->cols);
	if (!dp)
		return ;
	best.size = 0;
	best.row = 0;
	best.col = 0;
	init_first_row(map, dp, &best);
	i = 1;
	while (i < map->rows)
	{
		process_row(map, i, dp, &best);
		i = i + 1;
	}
	free(dp);
	fill_square(map, best.size, best.row, best.col);
}
