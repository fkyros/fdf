/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:44:17 by gade-oli          #+#    #+#             */
/*   Updated: 2023/12/27 20:36:10 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * creates and allocates the mlx window and memory image
 */
void	set_mlx(t_fdf *fdf)
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
	fdf->mlx->img = mlx_new_image(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!fdf->mlx->img)
		exit_error("error creating memory image");
	fdf->mlx->img_addr = mlx_get_data_addr(fdf->mlx->img, &fdf->mlx->bpp, \
            &fdf->mlx->line_length, &fdf->mlx->endian);
	if (!fdf->mlx->img_addr)
		exit_error("error allocating memory image");
}

//TODO: explain the offset formula !!!
//TODO: introduce color by argument
void	img_pixel_put(t_mlx *mlx, int x, int y)
{
	char	*pixel_pos;
	int		offset;
	int 	color;

	color = 0x00FFFFFF;
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
	mlx_string_put(mlx->ptr, mlx->win, 20, 20, TEXT_COLOR, \
			"ESC to exit");
}
