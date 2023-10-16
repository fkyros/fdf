/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:57:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/10/16 22:37:50 by gade-oli         ###   ########.fr       */
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
# include "defines.h"

int	ft_error(char *msg);

t_map   read_map(char *file);
void    free_matrix(char **matrix);

#endif
