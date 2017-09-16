/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 19:16:01 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/15 22:47:16 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	calc_iters(t_env *e, int row, int col, double temp)
{
	double	y;
	double	x;
	double	cr;
	double	ci;
	int		i;

	y = 0;
	x = 0;
	cr = 2.0 * (col - WIN_WSPLIT) / (0.5 * e->zoom * WINDOW_W) + e->x_off;
	ci = 2.0 * (row - WIN_HSPLIT) / (0.5 * e->zoom * WINDOW_H) + e->y_off;
	i = -1;
	while (SQR(x) + SQR(y) <= 4.0 && ++i < e->max)
	{
		temp = SQR(x) - SQR(y) + cr;
		y = 2 * fabs(x * y) + ci;
		x = temp;
	}
	return (i);
}

void		draw_ship(t_env *e, int row, int stop)
{
	int		i;
	int		col;
	double	temp;

	temp = 0;
	while (row < stop)
	{
		col = -1;
		while (++col < WINDOW_W)
		{
			i = calc_iters(e, row, col, temp);
			if (i == e->max)
				e->data[col + row * e->size / 4] = BLACK;
			else
				e->data[col + row * e->size / 4] = e->color_arr[i % 64];
		}
		row++;
	}
}
