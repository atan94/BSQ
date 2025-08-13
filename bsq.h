/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:24:46 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:31 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# ifndef BUF_SIZE
#  define BUF_SIZE 1024
# endif

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	fill;
	char	**grid;
}			t_map;

char		*read_line(int fd, int *len);
int			parse_header_line(char *header, t_map *map);
int			parse_map(int fd, t_map *map);
void		solve_map(t_map *map);
void		print_map(t_map *map);
void		free_map(t_map *map);

#endif
