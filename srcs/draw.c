/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:27:40 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/08 21:16:09 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	setup_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINDOW_W, WINDOW_H, e->name);
	e->image = mlx_new_image(e->mlx, WINDOW_W, WINDOW_H);
	e->data = (int*)mlx_get_data_addr(e->image, &e->bits, &e->size, &e->end);
	e->max = 100;
	e->zi = 0.0;
	e->zr = 0.0;
	e->ci = 0.0;
	e->cr = 0.0;
	e->xtrans = 0.0;
	e->ytrans = 0.0;
	e->zoom = 1.1;
}

void	draw_fract(t_env *e)
{
	setup_env(e);
	if (ft_strncmp(e->name, "Julia", 5))
	{
		printf("??????\n");
		draw_julia(e);
	}
	else if (ft_strncmp(e->name, "Mandle", 6))
		draw_mandle(e);
	else
		return (ft_putendl("error"));
}