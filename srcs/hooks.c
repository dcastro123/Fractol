/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:03:51 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/13 22:16:56 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	zoom_out(int x, int y, t_env *e)
{
	e->xtrans -= ((x - WIN_WSPLIT) / (WIN_WSPLIT / e->zoom) * 2);
	e->ytrans -= ((y - WIN_HSPLIT) / (WIN_HSPLIT) / e->zoom) *\
				(2 * WINDOW_H / WINDOW_W);
	e->zoom /= ZOOM_SCALE;
	e->xtrans += ((x - WIN_WSPLIT) / (WIN_WSPLIT / e->zoom) * 2);
	e->ytrans += ((y - WIN_HSPLIT) / (WIN_HSPLIT) / e->zoom) *\
				(2 * WINDOW_H / WINDOW_W);
	e->max--;
}

static	void	zoom_in(int x, int y, t_env *e)
{
	e->xtrans += ((x - WIN_WSPLIT) / (WIN_WSPLIT / e->zoom) * 2);
	e->ytrans += ((y - WIN_HSPLIT) / (WIN_HSPLIT / e->zoom) *\
			(2 * WINDOW_H / WINDOW_W));
	e->zoom *= ZOOM_SCALE;
	e->xtrans -= ((x - WIN_WSPLIT) / (WIN_WSPLIT / e->zoom) * 2);
	e->ytrans -= ((y - WIN_HSPLIT) / (WIN_HSPLIT / e->zoom) *\
			(2 * WINDOW_H / WINDOW_W));
	e->max++;
}

int				julia_mouse_hook(int x, int y, t_env *e)
{
	if (e->flag == 0 && x < WINDOW_W && y < WINDOW_H)
	{
		e->mouse_y = y - WIN_HSPLIT + 0.15;
		e->mouse_x = x - WIN_WSPLIT - 0.15;
	}
	draw_fract(e);
	return (0);
}

int				mouse_hooks(int button, int x, int y, t_env *e)
{
	if (button == M_UPSCRLL)
		zoom_in(x, y, e);
	else if (button == M_DWNSCRLL)
		zoom_out(x, y, e);
	draw_fract(e);
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
	else if (keycode == K_ESC)
		exit(0);
	draw_fract(e);
	return (0);
}
