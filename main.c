/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:12:48 by amtan             #+#    #+#             */
/*   Updated: 2025/08/13 14:55:16 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_stdin(void)
{
	t_map	map;

	if (parse_map(0, &map) == 0)
	{
		solve_map(&map);
		print_map(&map);
		free_map(&map);
	}
	else
	{
		write(1, "map error\n", 10);
	}
	return (0);
}

void	process_file(char *filename)
{
	t_map	map;
	int		fd;

	fd = open(argv[i], O_RDONLY);
	if (fd < 0)
		write(1, "map error\n", 10);
	else
		result = parse_map(fd, &map);
	close(fd);
	if (result == 0)
	{
		solve_map(&map);
		print_map(&map);
		free_map(&map);
	}
	else
		write(1, "map error\n", 10);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		process_stdin() retrun(0);
	}
	while (i < argc)
	{
		process_file(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}
