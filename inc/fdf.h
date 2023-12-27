/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:57:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/12/27 20:35:53 by gade-oli         ###   ########.fr       */
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
t_map	*read_map(char *file);

int		deal_key(int key, t_fdf *fdf);
void	print_map(t_fdf *fdf);
int		proper_extension(char *file);
int		get_map_width(char *file);
int		get_map_height(char *file);

void	img_pixel_put(t_mlx *mlx, int x, int y);
void    bresenham(t_fdf *fdf, t_point from, t_point to);
void	draw_map(t_fdf *fdf);
void	print_instructions(t_mlx *mlx);

int		ft_error(char *msg);
void	exit_error(char *msg);

void	free_matrix(char **matrix);
int	    ft_abs(int a);

#endif
