/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:44:17 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/17 22:23:06 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * creates and allocates the mlx window display and memory image to store the figure
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

/**
 * initialises map visual parameters that can later be changed through mlx events
*/
void	init_map_params(t_map *map)
{
	map->ceiling = 2;
	map->perspective = 45; //TODO: change the ids
}

//TODO: explain the offset formula !!!
//TODO: introduce color by argument
void	img_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel_pos;
	int		offset;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		offset = y * mlx->line_length + x * (mlx->bpp / 8);
		pixel_pos = mlx->img_addr + offset;
		*(unsigned int *)pixel_pos = color;
	}
	//else
	//	ft_printf("error displaying point (%d,%d) \
	//			-> out of bounds (%d, %d)\n", x, y, WIN_WIDTH, WIN_HEIGHT);
}

/**
 * displays on the screen how to interact with the program
*/
void	print_instructions(t_mlx *mlx)
{
	int y;

	y = 0;
	mlx_string_put(mlx->ptr, mlx->win, 20, y + 20, TEXT_COLOR, \
			"press ESC to exit");
	mlx_string_put(mlx->ptr, mlx->win, 20, y + 40, TEXT_COLOR, \
			"press P to change perspective");
}

// turns all the screen to black
void	clear_window(t_mlx *mlx)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			img_pixel_put(mlx, j, i, BLACK);
			j++;
		}
		i++;
	}
}

/**
 * erases (draws all in black) the screen and draws the fdf figure given the map parameters
*/
void	display_fdf(t_fdf *fdf)
{
	clear_window(fdf->mlx);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->win, fdf->mlx->img, 0, 0); //TODO: why two figures hell nah
	print_instructions(fdf->mlx);
}
