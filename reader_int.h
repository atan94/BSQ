/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:17:00 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:52 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_INT_H
# define READER_INT_H

# include "bsq.h"

typedef struct s_reader
{
	char	buf[BUF_SIZE];
	int		sz;
	int		idx;
}			t_reader;

typedef struct s_line
{
	char	*p;
	int		cap;
	int		len;
}			t_line;

#endif
