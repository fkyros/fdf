/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:57:04 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/22 17:41:08 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

//assuming MLX is located at /usr/local 
# include <mlx.h>

# include "defines.h"
# include "../libs/libft/libft.h"
# include "../libs/printf/inc/ft_printf.h"

//window.c
void	set_mlx(t_fdf *fdf);
void	img_pixel_put(t_mlx *mlx, t_point p);
void	print_instructions(t_mlx *mlx);
void	clear_window(t_mlx *mlx);
void	set_mlx_hooks(t_fdf *fdf);

//map.c
void	display_fdf(t_fdf *fdf);
void	init_params(t_fdf *fdf);
void	draw_map(t_fdf *fdf);
void	color_map(int key, t_fdf *fdf);
void	zoom_map(t_map *map, int control);

//parser.c
t_map	*read_map(char *file);
int		bad_extension(char *file);
int		get_map_width(char *file);
int		get_map_height(char *file);
void	fill_matrix(char *line, int *z_line);

//keyhooks.c
int		deal_close(t_fdf *fdf);
int		deal_key(int key, t_fdf *fdf);

//mousehooks.c
int		deal_click(int click, int x, int y, t_fdf *fdf);

//draw.c
void	bresenham(t_fdf *fdf, t_point from, t_point to);
t_point	get_point(t_map *map, int x, int y);

//utils/
int		ft_error(char *msg);
void	exit_error(char *msg);
void	free_matrix(char **matrix);
int		ft_abs(int a);

#endif
