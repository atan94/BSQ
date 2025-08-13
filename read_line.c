/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:07:23 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 17:19:51 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "reader_int.h"
#include <stdlib.h>
#include <unistd.h>

int	grow_line(char **p, int *cap, int need, int len)
{
	char	*n;
	int		i;
	int		nc;

	nc = *cap;
	while (need > nc)
		nc = nc * 2;
	n = (char *)malloc(nc);
	if (!n)
		return (-1);
	i = 0;
	while (i < len)
	{
		n[i] = (*p)[i];
		i = i + 1;
	}
	free(*p);
	*p = n;
	*cap = nc;
	return (0);
}

int	append_char(t_line *l, char c)
{
	if (l->len + 2 > l->cap)
	{
		if (grow_line(&(l->p), &(l->cap), l->len + 2, l->len) < 0)
			return (-1);
	}
	l->p[l->len] = c;
	l->len = l->len + 1;
	return (0);
}

int	try_refill(int fd, t_reader *r)
{
	if (r->idx < r->sz)
		return (1);
	r->sz = read(fd, r->buf, BUF_SIZE);
	if (r->sz <= 0)
	{
		r->sz = 0;
		r->idx = 0;
		return (0);
	}
	r->idx = 0;
	return (1);
}

int	fill_line(int fd, t_reader *r, t_line *l)
{
	while (1)
	{
		if (!try_refill(fd, r))
			return (0);
		if (r->buf[r->idx] == '\n')
		{
			r->idx = r->idx + 1;
			return (1);
		}
		if (append_char(l, r->buf[r->idx]) < 0)
		{
			free(l->p);
			l->p = NULL;
			return (0);
		}
		r->idx = r->idx + 1;
	}
}

char	*read_line(int fd, int *len)
{
	static t_reader	r;
	t_line			l;

	*len = 0;
	l.cap = 128;
	l.len = 0;
	l.p = (char *)malloc(l.cap);
	if (!l.p)
		return (NULL);
	if (!fill_line(fd, &r, &l))
	{
		if (!l.p)
			return (NULL);
		if (r.sz == 0 && l.len == 0)
		{
			free(l.p);
			return (NULL);
		}
	}
	l.p[l.len] = '\0';
	*len = l.len;
	return (l.p);
}
