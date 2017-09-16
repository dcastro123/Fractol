/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:20:46 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/15 22:37:34 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	setup_env(t_env *e)
{
	e->max = 64;
	e->flag = 0;
	e->y_off = 0.0;
	e->x_off = 0.0;
	e->zoom = 1.0;
	set_color(e);
}

void			run_frac(t_env *e)
{
	e->choice == 0 ? exit(0) : start_pthread(e);
	mlx_put_image_to_window(e->mlx, e->win, e->image, 0, 0);
}

static	void	init_win(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINDOW_W, WINDOW_H, "FRACTOL");
	e->image = mlx_new_image(e->mlx, WINDOW_W, WINDOW_H);
	e->data = (int*)mlx_get_data_addr(e->image, &e->bits, &e->size, &e->end);
	setup_env(e);
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
			error_opts();
		init_win(e);
		run_frac(e);
		controls();
		mlx_key_hook(e->win, key_hooks, e);
		mlx_mouse_hook(e->win, mouse_hooks, e);
		mlx_hook(e->win, 6, 0, julia_mouse_hook, e);
		mlx_loop(e->mlx);
	}
	return (0);
}
