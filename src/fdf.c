/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:58:30 by gade-oli          #+#    #+#             */
/*   Updated: 2023/08/22 20:32:58 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_window;

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "fdf");
	mlx_loop(mlx);
	return (0);
}
