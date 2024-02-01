/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:52 by gade-oli          #+#    #+#             */
/*   Updated: 2024/02/01 19:21:45 by gade-oli         ###   ########.fr       */
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
	fdf->mouse = malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		exit_error("error creating mouse instance");
	fdf->mouse->drag = 0;
	init_map_params(fdf->map);
	display_fdf(fdf);
	mlx_key_hook(fdf->mlx->win, deal_key, fdf);
	mlx_mouse_hook(fdf->mlx->win, deal_click, fdf);
	mlx_hook(fdf->mlx->win, RED_DESTROY, 0, deal_close, fdf);
	mlx_hook(fdf->mlx->win, MOUSE_PRESS, 0, deal_click, fdf);
    mlx_hook(fdf->mlx->win, MOUSE_RELEASE, 0, deal_release, fdf);
    mlx_hook(fdf->mlx->win, MOUSE_MOTION, 0, deal_mouse_motion, fdf);
	mlx_loop(fdf->mlx->ptr);
	return (SUCCESS);
}
