/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:19:01 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/08 15:29:53 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * initialises map visual parameters 
 * that can later be changed through mlx events
*/
void	init_params(t_fdf *fdf)
{
	fdf->map->zoom = 25;
	fdf->map->altitude = 4;
	fdf->map->perspective = DEG30INRAD;
	fdf->map->show_instructions = ON;
	fdf->map->translation_x = WIN_WIDTH / 2;
	fdf->map->translation_y = WIN_HEIGHT / 4;
	fdf->map->line_color = WHITE;
	fdf->mlx->text_color = TEXT_COLOR;
	fdf->mlx->background_color = BLACK;
}

/**
 * clears the screen and draws the 
 * fdf figure given the map parameters
*/
void	display_fdf(t_fdf *fdf)
{
	clear_window(fdf->mlx);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->win, \
			fdf->mlx->img, 0, 0);
	if (fdf->map->show_instructions)
		print_instructions(fdf->mlx);
}

/**
 * draws the fdf figure read from the input file
 */
void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(fdf, get_point(fdf->map, x, y), \
						get_point(fdf->map, x + 1, y));
			if (y < fdf->map->height - 1)
				bresenham(fdf, get_point(fdf->map, x, y), \
						get_point(fdf->map, x, y + 1));
			x++;
		}
		y++;
	}
}

void	color_map(int key, t_fdf *fdf)
{
	if (key == KEY_1)
	{
		fdf->map->line_color = WHITE;
		fdf->mlx->background_color = BLACK;
		fdf->mlx->text_color = TEXT_COLOR;
	}
	if (key == KEY_2)
	{
		fdf->map->line_color = CARBON;
		fdf->mlx->background_color = GRAY;
		fdf->mlx->text_color = CARBON;
	}
}

void	zoom_map(t_map *map, int control)
{
	if (control == PLUS)
		map->zoom += ZOOM_SHIFT;
	if (control == MINUS)
		map->zoom -= ZOOM_SHIFT;
	if (map->zoom < 0)
		map->zoom = 1;
}
