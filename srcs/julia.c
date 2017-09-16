/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 22:14:58 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/15 22:47:26 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	calc_iters(t_env *e, int row, int col)
{
	double	re_temp;
	double	i_temp;
	double	y;
	double	x;
	int		i;

	y = 2.0 * (row - WIN_HSPLIT) / (0.5 * e->zoom * WINDOW_H) + e->y_off;
	x = 2.0 * (col - WIN_WSPLIT) / (0.5 * e->zoom * WINDOW_W) + e->x_off;
	i = -1;
	while (++i < e->max && SQR(x) + SQR(y) <= 4.0)
	{
		re_temp = x;
		i_temp = y;
		x = SQR(re_temp) - SQR(i_temp) + (e->mouse_x * 4.0 / WINDOW_W - 2.0);
		y = 2 * (i_temp * re_temp) + (e->mouse_y * 4.0 / WINDOW_H - 2.0);
	}
	return (i);
}

void		draw_julia(t_env *e, int row, int stop)
{
	int	i;
	int	col;

	while (row < stop)
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
		row++;
	}
}
