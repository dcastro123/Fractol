/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:20:46 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/13 20:31:06 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	setup_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINDOW_W, WINDOW_H, "FRACTOL");
	e->image = mlx_new_image(e->mlx, WINDOW_W, WINDOW_H);
	e->data = (int*)mlx_get_data_addr(e->image, &e->bits, &e->size, &e->end);
	e->max = 64;
	e->zi = 0.0;
	e->zr = 0.0;
	e->ci = 0.0;
	e->cr = 0.0;
	e->flag = 0;
	e->xtrans = 0.0;
	e->ytrans = 0.0;
	e->zoom = 1.0;
}

int				main(int ac, char **av)
{
	t_env *e;

	if (ac != 2)
		display_opts();
	else
	{
		if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
			return (0);
		get_opt(av[1][0], e);
		if (!(e->choice))
		{
			display_opts();
			return (0);
		}
		setup_env(e);
		draw_fract(e);
		controls();
		mlx_key_hook(e->win, key_hooks, e);
		mlx_mouse_hook(e->win, mouse_hooks, e);
		mlx_hook(e->win, 6, 0, julia_mouse_hook, e);
		mlx_loop(e->mlx);
	}
	return (0);
}
