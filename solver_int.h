/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:40:26 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:55 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_INT_H
# define SOLVER_INT_H

# include "bsq.h"

typedef struct s_best
{
	int	size;
	int	row;
	int	col;
}		t_best;

void	update_best(t_best *b, int v, int i, int j);
void	init_first_row(t_map *map, int *dp, t_best *best);
void	process_row(t_map *map, int i, int *dp, t_best *best);
void	fill_square(t_map *map, int size, int row, int col);

#endif
