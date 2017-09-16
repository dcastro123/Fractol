/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:03:51 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/15 21:56:31 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	zoom_out(int x, int y, t_env *e)
{
	e->x_off -= NEW_XOFF(x, e->zoom);
	e->y_off -= NEW_YOFF(y, e->zoom);
	e->zoom /= ZOOM_SCALE;
	e->x_off += NEW_XOFF(x, e->zoom);
	e->y_off += NEW_YOFF(y, e->zoom);
	e->max--;
}

static	void	zoom_in(int x, int y, t_env *e)
{
	e->x_off += NEW_XOFF(x, e->zoom);
	e->y_off += NEW_YOFF(y, e->zoom);
	e->zoom *= ZOOM_SCALE;
	e->x_off -= NEW_XOFF(x, e->zoom);
	e->y_off -= NEW_YOFF(y, e->zoom);
	e->max++;
}

int				julia_mouse_hook(int x, int y, t_env *e)
{
	if (e->flag == 0 && x < WINDOW_W && y < WINDOW_H)
	{
		e->mouse_y = y;
		e->mouse_x = x;
	}
	run_frac(e);
	return (0);
}

int				mouse_hooks(int button, int x, int y, t_env *e)
{
	if (button == M_UPSCRLL || button == M_LCLICK)
		zoom_in(x, y, e);
	else if (button == M_DWNSCRLL || button == M_RCLICK)
		zoom_out(x, y, e);
	run_frac(e);
	return (0);
}

int				key_hooks(int keycode, t_env *e)
{
	if (keycode == K_PLUS)
		e->max++;
	else if (keycode == K_MINUS)
		e->max--;
	else if (keycode == K_SPCE)
		e->flag = 1;
	else if (keycode == K_LFT)
		e->x_off += .15;
	else if (keycode == K_RGHT)
		e->x_off -= .15;
	else if (keycode == K_UP)
		e->y_off += .15;
	else if (keycode == K_DWN)
		e->y_off -= .15;
	else if (keycode == K_ENT)
		e->flag = 0;
	else if (keycode == K_ESC)
		exit(0);
	run_frac(e);
	return (0);
}
