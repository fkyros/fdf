/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:57:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/03 15:24:20 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

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

int		ft_error(char *msg);
void	exit_error(char *msg);

void    free_matrix(char **matrix);

#endif
