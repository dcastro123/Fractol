/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:51:38 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/13 04:16:36 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	calc_iters(t_env *e, int row, int col)
{
	double	re_temp;
	double	i_temp;
	int		i;

	e->zi = (row - WINDOW_H / 2) / (0.5 * e->zoom * WINDOW_H) + e->ytrans;
	e->zr = (col - WINDOW_W / 2) / (0.5 * e->zoom * WINDOW_W) + e->xtrans;
	i = -1;
	while (++i < e->max)
	{
		re_temp = e->zr;
		i_temp = e->zi;
		e->zi = 2 * (i_temp * re_temp) + e->mouse_y / WINDOW_W;
		e->zr = SQR(re_temp) - SQR(i_temp) + e->mouse_x / WINDOW_W;
		// e->zi = 2 * (i_temp * re_temp) + e->mouse_y / WINDOW_W;
		// e->zr = SQR(re_temp) - SQR(i_temp) + e->mouse_x / WINDOW_W;
		if (SQR(e->zr) + SQR(e->zi) > 4)
			break ;
	}
	return (i);
}

/**
*	Formula for drawing the Julia set of Fractals
**/

void	draw_julia(t_env *e)
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
				e->data[col + row * e->size / 4] = BLACK;
			else
				e->data[col + row * e->size / 4] = e->color_arr[i % 64];
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
}