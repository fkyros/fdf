/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:35:49 by gade-oli          #+#    #+#             */
/*   Updated: 2024/02/01 19:36:28 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * executed when a mouse click is done INSIDE the display
 */
int deal_click(int click, int x, int y, t_fdf *fdf)
{
	if (!click)
		return (FAIL);
	fdf->mouse->click = click;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (click == MOUSELEFT || click == MOUSERIGHT)
		fdf->mouse->drag = 1;
	if (click == MOUSEUP)
		fdf->map->zoom += 5;
	if (click == MOUSEDOWN)
		fdf->map->zoom -= 5;
	display_fdf(fdf);
	return (SUCCESS);
}

int	deal_mouse_motion(int x, int y, t_fdf *fdf)
{
	if (!fdf->mouse->drag)
		return (FAIL);
	if (fdf->mouse->click == MOUSERIGHT)
	{
		if (fdf->mouse->x < x) //TODO
			fdf->map->altitude += 1;
		if (fdf->mouse->x > x) //TODO
			fdf->map->altitude -= 1;
	}
	//TODO: implement translation
	(void)y;
	display_fdf(fdf);
	return (SUCCESS);
}

int	deal_release(int click, int x, int y, t_fdf *fdf)
{
	if (!click)
		return (FAIL);
	fdf->mouse->drag = 0;
	(void)x;
	(void)y;
	display_fdf(fdf);
	return (SUCCESS);
}
