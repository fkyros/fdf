/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:59:02 by gade-oli          #+#    #+#             */
/*   Updated: 2023/12/26 23:25:18 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}
