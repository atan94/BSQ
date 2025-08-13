/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_rows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:43:19 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:33 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver_int.h"

int	row_cell_value(int left, int up, int diag, int is_obst)
{
	int	m;

	if (is_obst)
		return (0);
	m = up;
	if (left < m)
		m = left;
	if (diag < m)
		m = diag;
	return (m + 1);
}

void	init_first_row(t_map *map, int *dp, t_best *best)
{
	int	j;
	int	v;

	j = 0;
	while (j < map->cols)
	{
		if (map->grid[0][j] == map->obstacle)
			v = 0;
		else
			v = 1;
		dp[j] = v;
		update_best(best, v, 0, j);
		j = j + 1;
	}
}

void	process_row(t_map *map, int i, int *dp, t_best *best)
{
	int	j;
	int	prev_diag;
	int	left;
	int	up;

	prev_diag = dp[0];
	if (map->grid[i][0] == map->obstacle)
		left = 0;
	else
		left = 1;
	dp[0] = left;
	update_best(best, left, i, 0);
	j = 1;
	while (j < map->cols)
	{
		up = dp[j];
		left = row_cell_value(left, up, prev_diag,
				(map->grid[i][j] == map->obstacle));
		dp[j] = left;
		update_best(best, left, i, j);
		prev_diag = up;
		j = j + 1;
	}
}
