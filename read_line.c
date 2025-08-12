/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:07:23 by amtan             #+#    #+#             */
/*   Updated: 2025/08/12 22:20:40 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_line(int fd, int *len)
{
	static char	buffer[BUF_SIZE];
	static int	buf_size = 0;
	static int	buf_index = 0;
	char		*line;
	int			capacity;
	int			length;
	int			bytes_read;
	char		c;
	char		*new_line;
	int			i;

	*len = 0;
	capacity = 128;
	line = (char *)malloc(capacity * sizeof(char));
	if (!line)
		return (NULL);
	while (1)
	{
		if (buf_index >= buf_size)
		{
			bytes_read = read(fd, buffer, BUF_SIZE);
			if (bytes_read <= 0)
			{
				buf_size = 0;
				buf_index = 0;
				break ;
			}
			buf_size = bytes_read;
			buf_index = 0;
		}
		c = buffer[buf_index++];
		if (c == '\n')
			break ;
		if (length + 1 >= capacity)
		{
			capacity *= 2;
			new_line = (char *)malloc(capacity * sizeof(char));
			if (!new_line)
			{
				free(line);
				return (NULL);
			}
			i = 0;
			while (i < length)
			{
				new_line[i] = line[i];
				i++
			}
			free(line);
			line = new_line;
		}
		line[length++] = c;
	}
	if (buf_size == 0 && length == 0)
	{
		free(line);
		*len = 0;
		return (NULL);
	}
	if (length >= capacity)
	{
		new_line = (char *)
	}
}
