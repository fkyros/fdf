/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:44:17 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/24 13:03:20 by gade-oli         ###   ########.fr       */
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
	fdf->mlx->win = mlx_new_window(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!fdf->mlx->win)
		exit_error("error creating window display");
}

//TODO: explain the offset formula !!!
//TODO: introduce color by argument
void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel_pos;
	int		offset;

	if (x >= 0 && x <= WIN_WIDTH && y >= 0 && y <= WIN_HEIGHT)
	{
		offset = y * mlx->line_length + x * (mlx->bpp / 8);
		pixel_pos = mlx->img_addr + offset;
		*(unsigned int *)pixel_pos = color;
	}
	else
		ft_printf("error displaying point (%d,%d) \
				-> out of bounds (%d, %d)\n", x, y, WIN_WIDTH, WIN_HEIGHT);
}

void	print_instructions(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 300, 300, TEXT_COLOR, \
			"ESC to exit");
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
