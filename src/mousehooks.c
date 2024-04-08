/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:35:49 by gade-oli          #+#    #+#             */
/*   Updated: 2024/04/08 15:29:57 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/**
 * executed when a mouse click is done INSIDE the display
 */
int	deal_click(int click, int x, int y, t_fdf *fdf)
{
	if (!click)
		return (FAIL);
	fdf->mouse->click = click;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (click == MOUSEUP)
		zoom_map(fdf->map, PLUS);
	if (click == MOUSEDOWN)
		zoom_map(fdf->map, MINUS);
	display_fdf(fdf);
	return (SUCCESS);
}
