/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:07:23 by amtan             #+#    #+#             */
/*   Updated: 2025/08/12 23:40:19 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	grow_line(char **line, int *cap, int need, int len)
{
	char	*n;
	int		i;
	int		newcap;

	newcap = *cap;
	while (need > newcap)
		newcap *= 2;
	n = (char *)malloc(newcap);
	if (!n)
		return (-1);
	i = 0;
	while (i < len)
	{
		n[i] = (*line)[i];
		i++;
	}
	free(*line);
	*line = n;
	*cap = newcap;
	return (0);
}

int	rl_try_refill(int fd, char *buf, int *sz, int *idx)
{
	if (*idx < *sz)
		return (1);
	*sz = read(fd, buf, BUF_SIZE);
	if (*sz <= 0)
	{
		*sz = 0;
		*idx = 0;
		return (0);
	}
	*idx = 0;
	return (1);
}

int	rl_append_or_fail(char **line, int *cap, int *len, char c)
{
	if (*len + 2 > *cap)
	{
		if (grow_line(line, cap, *len + 2, *len) < 0)
			return (-1);
	}
	(*line)[(*len)++] = c;
	return (0);
}

int	fill_line(int fd, char *buf, int *sz, int *idx, char **pline, int *cap,
		int *len)
{
	while (1)
	{
		if (!rl_try_refill(fd, buf, sz, idx))
			return (0);
		if (buf[*idx] == '\n')
		{
			(*idx)++;
			return (1);
		}
		if (rl_append_or_fail(pline, cap, len, buf[*idx]) < 0)
		{
			free(*pline);
			*pline = NULL;
			return (0);
		}
		(*idx)++;
	}
}

char	*read_line(int fd, int *len)
{
	static char	buf[BUF_SIZE];
	static int	sz;
	static int	idx;
	char		*line;
	int			cap;

	*len = 0;
	cap = 128;
	line = (char *)malloc(cap);
	if (!line)
		return (NULL);
	if (!fill_line(fd, buf, &sz, &idx, &line, &cap, len))
	{
		if (!line)
			return (NULL);
		if (sz == 0 && *len == 0)
		{
			free(line);
			return (NULL);
		}
	}
	line[*len] = '\0';
	return (line);
}
