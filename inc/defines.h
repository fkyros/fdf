/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:48:49 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/03 15:38:18 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DEFINES_H
# define DEFINES_H

# define WIN_NAME "gade-oli fdf :)"
# define WIN_WIDTH 720
# define WIN_HEIGHT 480

# define PGUP 126
# define PGDOWN 125
# define PGLEFT 123
# define PGRIGHT 124
# define W 13
# define A 0
# define S 1
# define D 2
# define SPACE 49
# define ESC 53
# define CCENTER 8
# define X 7
# define Q 12

# ifndef FAIL
#  define FAIL 1
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

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
}	t_map;

typedef struct s_fdf
{
	t_map	*map;
	t_mlx	*mlx;
}	t_fdf;

#endif
