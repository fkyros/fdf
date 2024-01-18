/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:48:49 by gade-oli          #+#    #+#             */
/*   Updated: 2024/01/18 20:13:13 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_NAME "gade-oli fdf :)"
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define ZOOM 20
# define DEG45INRAD 0.78539816 //45º = pi/6 rads
# define DEG30INRAD 0.52359877 //30º = pi/4 rads

# define PGUP 126
# define PGDOWN 125
# define PGLEFT 123
# define PGRIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define PLUS 30 
# define MINUS 44
# define SPACE 49 //change color progressively while pressed?
# define C 8 //center raster 
# define P 35 //change perspective
# define R 15 //reset values for zoom and position to default
# define M 46 //increase ceiling
# define N 45 //reduce ceiling
# define Z 6 //enter/exit zen mode
# define MOUSELEFT 1 //translate the figure by dragging
# define MOUSERIGHT 2 //increase/decrease altitude by dragging
# define MOUSEMIDDLE 3 //rotate the figure by dragging
# define MOUSEUP 4 //scroll with your finger upwards on the mouse wheel
# define MOUSEDOWN 5
# define RED_DESTROY 17 //red button cross from the display

# define BLACK 0
# define WHITE 0x00FFFFFF

# define FAIL 1
# define SUCCESS 0

# define ON 1
# define OFF 0

# define TEXT_COLOR 0x00EAEAEA

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		padding;
	int		altitude;
	float	perspective;
	int		show_instructions;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_fdf
{
	t_map	*map;
	t_mlx	*mlx;
}	t_fdf;

#endif
