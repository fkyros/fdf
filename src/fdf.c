/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:52 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/24 13:15:09 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (ft_error("usage: ./fdf <map_name>\n"));
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		exit_error("error creating fdf");
	fdf->map = generate_map(argv[1]);
	print_map(fdf);	
	create_window(fdf);

	fdf->mlx->img = mlx_new_image(fdf->mlx->ptr, WIN_WIDTH, WIN_HEIGHT);
    if (!fdf->mlx->img)
        exit_error("error creating the image");
	fdf->mlx->img_addr = mlx_get_data_addr(fdf->mlx->img, &fdf->mlx->bpp, \
			&fdf->mlx->line_length, &fdf->mlx->endian);

	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->win, fdf->mlx->img, 0, 0);
	
	print_instructions(fdf->mlx);
	mlx_key_hook(fdf->mlx->win, deal_key, fdf);
	mlx_loop(fdf->mlx->ptr);
	return (SUCCESS);
}
