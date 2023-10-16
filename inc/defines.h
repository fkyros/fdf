/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:48:49 by gade-oli          #+#    #+#             */
/*   Updated: 2023/10/16 22:19:00 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEFINES_H
# define DEFINES_H

# define WIN_NAME "gade-oli fdf :)"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define ENDIAN 0 //little endian for intel-based computers

# define FAIL 1
# define SUCCESS 0

# define TEXT_COLOR 0x00EAEAEA

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_matrix;
}	t_map;

typedef struct s_fdf
{
	t_map map;
}	t_fdf;

#endif
