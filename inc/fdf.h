/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:57:04 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/18 12:16:05 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include <mlx.h>
# include "../libs/libft/libft.h"
# include "../libs/printf/inc/ft_printf.h"
# include "defines.h"

void	set_mlx(t_fdf *fdf);
void	display_fdf(t_fdf *fdf);
void	img_pixel_put(t_mlx *mlx, int x, int y, int color);
void	print_instructions(t_mlx *mlx);
void	init_map_params(t_map *map);

t_map	*read_map(char *file);
int		proper_extension(char *file);
int		get_map_width(char *file);
int		get_map_height(char *file);

int		deal_close(t_fdf *fdf);
int		deal_click(int click, int x, int y, t_fdf *fdf);
int		deal_key(int key, t_fdf *fdf);

void    bresenham(t_fdf *fdf, t_point from, t_point to);
void	draw_map(t_fdf *fdf);
void	apply_zoom(t_map *map, t_point *point);

int		ft_error(char *msg);
void	exit_error(char *msg);
void	free_matrix(char **matrix);
int	    ft_abs(int a);

#endif
