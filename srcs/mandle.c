/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:51:47 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/08 20:55:35 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	calc_iters(t_env *e, int row, int col)
{
	double	zrsqr;
	double	zisqr;
	int		i;

	e->zi = 0;
	e->zr = 0;
	zrsqr = SQR(e->zr);
	zisqr = SQR(e->zi);
// 	e->cr = (col - WINDOW_W/2.0) * 4.0 / WINDOW_W * e->zoom + e->xtrans;
// 	e->ci = (row - WINDOW_H/2.0) * 4.0 / WINDOW_W * e->zoom + e->ytrans;
	e->cr = ((4.0 * col / WINDOW_W - 2.0) / e->zoom)
		+ (e->xtrans / WINDOW_W);
	e->ci = ((4.0 * row / WINDOW_H - 2.0) / e->zoom)
		+ (e->ytrans / WINDOW_H);
	i = -1;
	while (zrsqr + zisqr <= 4.0 && ++i < e->max)
	{
		e->zi = (e->zr + e->zi)  * (e->zr + e->zi) - zrsqr - zisqr;
		e->zi += e->ci;
		e->zr = (zrsqr - zisqr) + e->cr;
		zrsqr = SQR(e->zr);
		zisqr = SQR(e->zi);
	}
	return (i);
}

/**
*	Formula for drawing the Mandlebrot set of Fractals
**/

void	draw_mandle(t_env *e)
{
	int	i;
	int	row;
	int	col;

	row = -1;
	while (++row < WINDOW_H)
	{
		col = -1;
		while(++col < WINDOW_W)
		{
			i = calc_iters(e, row, col);
			if (i == e->max)
				e->data[col + row * e->size / 4] = WHITE;
			else
				e->data[col + row * e->size / 4] = 130 * i / 2.5;
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
}
