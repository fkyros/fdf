/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:20:37 by gade-oli          #+#    #+#             */
/*   Updated: 2023/10/16 22:44:38 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

int	get_map_width(char *file)
{
	int		width;
	int		fd;
	char	*line;
	char	**matrix;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_error("invalid file: cannot open it");
		return (0);
	}
	line = get_next_line(fd);
	matrix = ft_split(line, ' ');
	width = 0;
	while (matrix[width])
		width++;
	free_matrix(matrix);
	close(fd);
	return (width);
}

int	get_map_height(char *file)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_error("invalid file: cannot open it");
		return (0);
	}
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

t_map	read_map(char *file)
{
	t_map	map;

	map.width = get_map_width(file);
	map.height = get_map_height(file);
	//if (!map.width || !map.height)
	//	return (NULL);
	//TODO: entregar direcciones en vez de stack
	return (map);
}
