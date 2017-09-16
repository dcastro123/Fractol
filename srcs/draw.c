/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:27:40 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/15 22:35:53 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			set_color(t_env *e)
{
	int				i;
	float			frequency;

	e->color_arr = (int*)malloc(sizeof(int) * e->max);
	frequency = 0;
	i = -1;
	while (++i < e->max)
	{
		e->r = (cos(frequency) + 1) * 127;
		e->g = (sin(frequency) + 1) * 127;
		e->b = (-cos(frequency) + 1) * 127;
		e->color_arr[i] = e->b | e->g << 4 | e->r << 16;
		frequency += M_PI / e->max;
	}
}

void			*draw_fract(void *arg)
{
	t_thread	*t;

	t = (t_thread*)arg;
	if (t->e->choice == 1)
		draw_julia(t->e, t->y - 1, t->ydist);
	else if (t->e->choice == 2)
		draw_mandel(t->e, t->y - 1, t->ydist);
	else if (t->e->choice == 3)
		draw_ship(t->e, t->y - 1, t->ydist);
	return ((void*)t);
}

void			start_pthread(t_env *e)
{
	pthread_t	thread[THREAD_COUNT];
	t_thread	env[THREAD_COUNT];
	int			i;
	int			ydist;

	i = -1;
	ydist = WINDOW_H / THREAD_COUNT;
	while (++i < THREAD_COUNT)
	{
		env[i].e = e;
		env[i].y = ydist * i;
		if (i == THREAD_COUNT - 1)
			env[i].ydist = WINDOW_H;
		else
			env[i].ydist = env[i].y + ydist;
		pthread_create(&thread[i], NULL, draw_fract, &env[i]);
	}
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(thread[i], NULL);
}
