/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:57:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/24 14:28:34 by gade-oli         ###   ########.fr       */
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

void	create_window(t_fdf *fdf);
t_map   *read_map(char *file);
void	create_image(t_mlx *mlx);
t_map	*generate_map(char *file);

int		deal_key(int key, t_fdf *fdf);
void	print_map(t_fdf *fdf);
int		proper_extension(char *file);
int		get_map_width(char *file);
int		get_map_height(char *file);

void	my_pixel_put(t_mlx *mlx, int x, int y, int color);
void	bresenham(int x1, int y1, int x2, int y2, t_fdf *fdf);
void	draw_map(t_fdf *fdf);
void	print_instructions(t_mlx *mlx);

int		ft_error(char *msg);
void	exit_error(char *msg);

void    free_matrix(char **matrix);

#endif
