/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:51:47 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/01 16:59:47 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// static	void	colors(t_env *e)
// {
// 	int	i;

// 	e->colors = (int*)ft_memalloc(e->max);
// 	while (i < max)
// 	{
// 		e->colors[i] = 
// 	}
// }

static	int	calc_iters(t_env *e, int row, int col)
{
	double	zrsqr;
	double	zisqr;
	int		i;

	e->zi = 0;
	e->zr = 0;
	zrsqr = SQR(e->zr);
	zisqr = SQR(e->zi);
	e->cr = (col - WINDOW_W/2.0) * 4.0 / WINDOW_W + e->xtrans;
	e->ci = (row - WINDOW_H/2.0) * 4.0 / WINDOW_W + e->ytrans;
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
	col = -1;
	while (++row < WINDOW_H)
	{
		col = -1;
		while(++col < WINDOW_W)
		{
			i = calc_iters(e, row, col);
			if (i < e->max)
				mlx_pixel_put(e->mlx, e->win, col, row, BLACK);
			else
				mlx_pixel_put(e->mlx, e->win, col, row, WHITE); 
		}
	}
}

// void	mandle(t_env *e)
// {






// }
