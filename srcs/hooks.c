/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:03:51 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/28 21:30:34 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
/*
static	int		julia_mouse_hook(int x, int y, int keycode, t_env *e)
{
	
	
	
}
*/
static	void		zoom_out(int x, int y, int keycode, t_env *e)
{
	e->zoom /= .70;
	e->xtrans -= ((x-(WINDOW_W / 2)) / ((WINDOW_W / 2) / e->zoom) *2);
	e->ytrans -=  ((y - (WINDOW_H / 2)) / ((WINDOW_H / 2) / e->zoom) *\
		       ( 2 * WINDOW_H / WINDOW_W));
	e->max++;
}
	
static	void		zoom_in(int x, int y, int keycode, t_env *e)
{
	e->zoom *= .70;
	e->xtrans += ((x-(WINDOW_W / 2)) / ((WINDOW_W / 2) / e->zoom) *2);
	e->ytrans +=  ((y - (WINDOW_H / 2)) / ((WINDOW_H / 2) / e->zoom) *\
		       ( 2 * WINDOW_H / WINDOW_W));
	e->max++;
}

int			mouse_hooks(int x, int y, int keycode, t_env *e)
{
	if (keycode == 4)
		zoom_in(x, y, keycode, e);
	else if (keycode == 5)
		zoom_out(x ,y keycode, e);
	//draw_fract(e->name);
 	return (0);
}

int			key_hooks(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
		e->max++;
	else if (keycode == 78)
		e->max--;
	//draw_fract(e->name);
	return (0);
}
