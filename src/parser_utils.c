/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:35:33 by gade-oli          #+#    #+#             */
/*   Updated: 2024/02/01 20:33:25 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * writes on the z-dimension array the given altitude
 */
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

/**
 * checks if the input file is named correctly
 */
int	bad_extension(char *file)
{
	char	*extension;

	extension = ft_strrchr(file, '.');
	if (!extension)
		return (FAIL);
	if (ft_strcmp(extension, ".fdf"))
		return (FAIL);
	return (SUCCESS);
}
