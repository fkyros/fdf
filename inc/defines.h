/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:48:49 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/22 17:41:52 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIN_NAME "gade-oli fdf :)"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

# define DEG45INRAD 0.78539816 //45º = pi/6 rads
# define DEG30INRAD 0.52359877 //30º = pi/4 rads
# define ZOOM_SHIFT 5
# define MOUSE_ALTITUDE_SHIFT 0.5
# define ALTITUDE_SHIFT 2
# define TRANSLATION_SHIFT 15

# ifdef __linux__
#  define PGUP 65362
#  define PGDOWN 65364
#  define PGLEFT 65361
#  define PGRIGHT 65363
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
#  define PLUS 43
#  define MINUS 45
#  define SPACE 32 //change line color progressively while pressed?
#  define C 99 //center raster
#  define P 112 //change perspective
#  define I 105
#  define O 111
#  define R 114 //reset values for zoom and position to default
#  define M 109 //increase ceiling
#  define N 110 //reduce ceiling
#  define Z 122 //enter/exit zen mode
#  define KEY_1 49
#  define KEY_2 50
# endif

# ifdef __APPLE__
#  define PGUP 126
#  define PGDOWN 125
#  define PGLEFT 123
#  define PGRIGHT 124
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define ESC 53
#  define PLUS 30 
#  define MINUS 44
#  define SPACE 49 //change line color progressively while pressed?
#  define C 8 //center raster 
#  define P 35 //change perspective
#  define I 34
#  define O 31
#  define R 15 //reset values for zoom and position to default
#  define M 46 //increase ceiling
#  define N 45 //reduce ceiling
#  define Z 6 //enter/exit zen mode
#  define KEY_1 18
#  define KEY_2 19
# endif

# define MOUSELEFT 1 //translate the figure by dragging
# define MOUSERIGHT 2 //increase/decrease altitude by dragging
# define MOUSEMIDDLE 3 //rotate the figure by dragging
# define MOUSEUP 4 //scroll with your finger upwards on the mouse wheel
# define MOUSEDOWN 5

# define RED_DESTROY 17 //red button cross from the display
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOTION 6

# define BLACK 0
# define WHITE 0x00FFFFFF
# define GRAY 0xBBBBBB
# define CARBON 0x151515

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
	int		background_color;
	int		text_color;
}	t_mlx;

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		padding;
	float	altitude;
	float	perspective;
	int		show_instructions;
	int		translation_x;
	int		translation_y;
	int		line_color;
	//int		top_color;
	//int		bottom_color;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_mouse
{
	int	click;
	int	x;
	int	y;
}	t_mouse;

typedef struct s_fdf
{
	t_map	*map;
	t_mlx	*mlx;
	t_mouse	*mouse;
}	t_fdf;

#endif
