/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:03:51 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/08 21:14:46 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void		zoom_out(int x, int y, t_env *e)
{
	e->zoom /= .70;
	e->xtrans -= ((x-(WINDOW_W / 2)) / ((WINDOW_W / 2) / e->zoom) * 2);
	e->ytrans -=  ((y - (WINDOW_H / 2)) / ((WINDOW_H / 2) / e->zoom) *\
		       ( 2 * WINDOW_H / WINDOW_W));
	e->max--;
}
	
static	void		zoom_in(int x, int y, t_env *e)
{
	e->zoom *= .70;
	e->xtrans += ((x-(WINDOW_W / 2)) / ((WINDOW_W / 2) / e->zoom) * 2);
	e->ytrans +=  ((y - (WINDOW_H / 2)) / ((WINDOW_H / 2) / e->zoom) *\
		       ( 2 * WINDOW_H / WINDOW_W));
	e->max++;
}

int			mouse_hooks(int button, int x, int y, t_env *e)
{
	if (button == M_UPSCRLL)
		zoom_in(x, y, e);
	else if (button == M_DWNSCRLL)
		zoom_out(x , y, e);
	draw_fract(e);
 	return (0);
}

int			key_hooks(int keycode, t_env *e)
{
	if (keycode == K_ESC)
		exit(0);
	else if (keycode == K_PLUS)
		e->max++;
	else if (keycode == K_MINUS)
		e->max--;
	draw_fract(e);
	return (0);
}
