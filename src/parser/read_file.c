/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:20:37 by gade-oli          #+#    #+#             */
/*   Updated: 2023/10/23 22:50:38 by gade-oli         ###   ########.fr       */
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
		exit_error("cannot open the map");
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
		exit_error("cannot open the map");
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

void	fill_matrix(char *line, int *z_line)
{
	int		i;
	char	**nums;

	nums = ft_split(line, ' '); 
	if (!nums)
		exit_error("memory error on split in fill_matrix");
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

t_map	*read_map(char *file)
{
	t_map	*map;
	int		i;
	int 	fd;
	char	*line;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("memory error while creating map");
	map->width = get_map_width(file);
	map->height = get_map_height(file);
	if (!map->width || !map->height)
		exit_error("map not valid");
	i = 0;
	map->z_matrix = malloc(sizeof(int *) * map->height + 1);
	while (i < map->height + 1)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width + 1); //TODO: +1??
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("cannot open map");
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
	return (map);
}