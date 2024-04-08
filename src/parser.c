/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:20:37 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/08 14:57:56 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	count_and_check_line_width(char **matrix, char *line)
{
	int	re_width;
	int	width;

	width = 0;
	re_width = 0;
	matrix = ft_split(line, ' ');
	if (!width)
		while (matrix[width])
			width++;
	else
	{
		while (matrix[re_width])
			re_width++;
		if (width != re_width)
			exit_error("bad map format: different line widths");
	}
	free_matrix(matrix);
	free(line);
	return (width);
}

//checks only the first line of the map
int	get_map_width(char *file)
{
	int		width;
	int		fd;
	char	*line;
	char	**matrix;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("cannot open the file");
	line = get_next_line(fd);
	matrix = NULL;
	while (line)
	{
		width = count_and_check_line_width(matrix, line);
		line = get_next_line(fd);
	}
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
		exit_error("cannot open the file");
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

void	create_and_fill_z_matrix(t_map *map, char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map->z_matrix = malloc(sizeof(int *) * (map->height + 1));
	while (i < map->height)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("cannot open the file");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		fill_matrix(line, map->z_matrix[i]);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map->z_matrix[i] = NULL;
	close(fd);
}

t_map	*read_map(char *file)
{
	t_map	*map;

	if (bad_extension(file))
		exit_error("map file has to be an .fdf extension");
	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("memory error while creating map");
	map->width = get_map_width(file);
	map->height = get_map_height(file);
	if (!map->width || !map->height)
		exit_error("map not valid");
	create_and_fill_z_matrix(map, file);
	return (map);
}
