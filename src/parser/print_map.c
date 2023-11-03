/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:54:53 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/03 14:57:39 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	print_map(t_fdf *fdf)
{
	int	i;
	int	j;

	ft_printf("map width: %d\nmap height: %d\n", fdf->map->width, fdf->map->height);
	i = 0;
	while(i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			printf("%3d ", fdf->map->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
