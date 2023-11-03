/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:44:17 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/03 19:04:55 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	create_window(t_fdf *fdf)
{
	fdf->mlx = malloc(sizeof(t_mlx));
	if (!fdf->mlx)
		exit_error("memory error creating display manager");
	fdf->mlx->ptr = mlx_init();
	if (!fdf->mlx->ptr)
		exit_error("error connecting to the graphical system");
	fdf->mlx->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!fdf->mlx->win)
		exit_error("error creating window display");
}

//TODO: explain the offset formula !!!
//TODO: introduce color by argument
void	my_pixel_put(t_mlx *mlx, int x, int y)
{
	char	*pixel_pos;
	int		offset;
	int 	color;

	color = 0x00FF0000;
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	offset = y * mlx->line_length + x * (mlx->bpp / 8);
	pixel_pos = mlx->img_addr + offset;
	*(unsigned int *)mlx->img_addr = color;
}

void	create_image(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img)
		exit_error("error creating the image");
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
	//if (mlx->bpp != 32)
	//	exit_error("system not supported: bpp != 32");
	
	//TODO: meter support a distintos bpp¿
	//TODO: pintar
	//mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}
