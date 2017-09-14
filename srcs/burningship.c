/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 19:16:01 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/13 23:05:01 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	calc_iters(t_env *e, int row, int col)
{
	double	zrsqr;
	double	zisqr;
	double	temp;
	int		i;

	e->zi = 0;
	e->zr = 0;
	zrsqr = SQR(e->zr);
	zisqr = SQR(e->zi);
	e->cr = (col - WIN_WSPLIT) * 4.0 / WINDOW_W * e->zoom + e->xtrans;
	e->ci = (row - WIN_HSPLIT) * 4.0 / WINDOW_W * e->zoom + e->ytrans;
	i = -1;
	while (zrsqr + zisqr <= 4.0 && ++i < e->max)
	{
		temp = fabs(zrsqr - zisqr + e->cr);
		// e->zi = (e->zr + e->zi) * (e->zr + e->zi) - zrsqr - zisqr;
		// e->zi += e->ci;
		e->zi = fabs(2 * (e->zr * e->zi) + e->ci);
		// e->zr = (zrsqr - zisqr) + e->cr;
		e->zr = temp;
		zrsqr = SQR(e->zr);
		zisqr = SQR(e->zi);
	}
	return (i);
}

void		draw_ship(t_env *e)
{
	int	i;
	int	row;
	int	col;

	row = -1;
	while (++row < WINDOW_H)
	{
		col = -1;
		while (++col < WINDOW_W)
		{
			i = calc_iters(e, row, col);
			if (i == e->max)
				e->data[col + row * e->size / 4] = BLACK;
			else
				e->data[col + row * e->size / 4] = e->color_arr[i % 64];
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
}
