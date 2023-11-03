/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:14:13 by gade-oli          #+#    #+#             */
/*   Updated: 2023/11/03 15:39:11 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

//TODO: when x pressed on the window corner, exit clean

int	deal_key(int key, t_fdf *fdf)
{
	//TODO: check if the key pressed is valid
	//ft_printf("key pressed: %d\n", key);
	if (key == ESC)
		exit(0);
	(void)fdf;
	return (0);
}
