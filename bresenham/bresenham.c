/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:25:07 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/28 20:23:33 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define FAIL 1

#define WIN_WIDTH 720
#define WIN_HEIGHT 480
#define WIN_NAME "bresenham"

#define ESC 53

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
}	t_mlx;

int	free_all(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	free(mlx->ptr);
	free(mlx->win);
	free(mlx->img);

	free(mlx);
	return (FAIL);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
}

int	deal_key(int key, t_mlx *mlx)
{
	if (key == ESC)
		free_all(mlx);
	else
		printf("eeeeeeeeee\n");
	return (SUCCESS);
}

void	my_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pos;
	int		offset;

	offset = (y * mlx->size_line) + (x * mlx->bpp/8);
	pos = mlx->img + offset;
	(unsigned char) pos = color;
}

int	main(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (FAIL);
	init_mlx(mlx);
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (free_all(mlx));
	mlx->win = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!mlx->win)
		return (free_all(mlx));

	//get info to write pixels on window
	mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img = mlx_get_data_addr(mlx->img, mlx->ptr, mlx->bpp, mlx->size_line, mlx->endian);


	//pintar rectas con bresenham
	

	mlx_key_hook(mlx->win, &deal_key, mlx);
	mlx_loop(mlx->ptr);
	return (SUCCESS);
}
