/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:27:40 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/13 22:47:09 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	get_colors(t_env *e)
{
	int				i;
	float			f;

	e->color_arr = (int*)malloc(sizeof(int) * e->max);
	f = 0;
	i = -1;
	while (++i < e->max)
	{
		e->r = (cos(f) + 1) * 127;
		e->g = (sin(f) + 1) * 127;
		e->b = (-cos(f) + 1) * 127;
		e->color_arr[i] = e->b | e->g << 8 | e->r << 16;
		f += M_PI / e->max;
	}
}

void			draw_fract(t_env *e)
{
	get_colors(e);
	if (e->choice == 1)
		draw_julia(e);
	else if (e->choice == 2)
		draw_mandel(e);
	else if (e->choice == 3)
		draw_ship(e);
	else if (e->choice == 4)
		draw_clover(e);
}