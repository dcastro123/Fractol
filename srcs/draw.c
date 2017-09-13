/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:27:40 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/12 22:22:00 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	get_colors(t_env *e)
{
	int				i;
	float			f;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	e->color_arr = (int*)malloc(sizeof(int) * e->max);
	f = 0;
	i = -1;
	while (++i < e->max)
	{
		r = (cos(f) + 1) * 127;
		g = (sin(f) + 1) * 127;
		b = (-cos(f) + 2) * 127;
		e->color_arr[i] = b << 8 | g << 8 | r << 6;
		f += M_PI / e->max;
	}
}

void	draw_fract(t_env *e)
{
	get_colors(e);
	if (e->choice == 1)
		draw_julia(e);
	else if (e->choice == 2)
		draw_mandle(e);
	else
		return (ft_putendl("error"));
}