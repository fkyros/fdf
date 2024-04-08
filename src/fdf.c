/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:52 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/08 14:58:55 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (ft_error("usage: ./fdf <map_name>"));
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		exit_error("error creating fdf");
	fdf->map = read_map(argv[1]);
	set_mlx(fdf);
	init_params(fdf);
	display_fdf(fdf);
	set_mlx_hooks(fdf);
	mlx_loop(fdf->mlx->ptr);
	return (SUCCESS);
}
