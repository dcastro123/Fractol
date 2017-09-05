/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:51:38 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/04 19:08:47 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	int	calc_iters(t_env *e, int row, int col)
{
	double	re_temp;
	double	i_temp;
	int		i;

	e->zi = (row - WINDOW_H / 2) / (0.5 * ZOOM * row) + e->ytrans;
	e->zr =  1.5 * (col - WINDOW_W / 2) / (0.5 * ZOOM * col) + e->xtrans;
	re_temp = 0;
	i_temp = 0;
	e->cr = -0.7;
	e->ci = 0.27015;
	i = -1;
	while (++i < e->max)
	{
		re_temp = e->zr;
		i_temp = e->zi;
		e->zi = 2 * (i_temp * re_temp) + e->ci;
		e->zr = SQR(re_temp) - SQR(i_temp) + e->cr;
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