/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:52 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/03 11:12:36 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (ft_error("usage: ./fdf <map_name>\n"));
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		exit_error("error creating fdf");
	fdf->map = generate_map(argv[1]);
	printf("map width: %d\nmap height: %d\n", fdf->map->width, fdf->map->height);
	
	//TODO: hacer funcion de visualizacion
	int i, j;
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

	//11:44
	//create_window(fdf);
	//create_image(fdf->mlx);
	//mlx_loop(fdf->mlx->ptr);
	return (SUCCESS);
}
