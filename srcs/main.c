/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:20:46 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/04 18:58:49 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static void	display_opts(void)
{
	ft_putendl("Usage: ./fractol [option number]");
	ft_putstr("Valid Options:\n\
		1: Julia\n\
		2: Mandlebrot\n\
		3. WIP\n");
}

static	void	get_opt(char s, t_env *e)
{
	if (s == '1')
		e->name = ft_strdup("Julia");
	else if (s == '2')
		e->name = ft_strdup("Mandlebrot");
	else if (s == '3')
		e->name = ft_strdup("WIP");
}

static	void	setup_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINDOW_W, WINDOW_H, e->name);
	e->max = 50;
	e->zi = 0.0;
	e->zr = 0.0;
	e->ci = 0.0;
	e->cr = 0.0;
	e->xtrans = 0;
	e->ytrans = 0;
}

static	void	controls(void)
{
	ft_putendl("CONTROLS:\n");
	ft_putendl("Zoom In/Out: Mousewheel Up/Down\n");
	ft_putendl("Increase/Decrease Iteration: Up Arrow/Down Arrow\n");
	ft_putendl("Add/Remove color: z/c\n");
}

int	main(int ac, char **av)
{
	t_env *e;

	if (ac != 2)
		display_opts();
	else
	{
		if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
			return (0);
		get_opt(av[1][0], e);
		if (!(e->name))
		{
			display_opts();
			return (0);
		}
		setup_env(e);
		controls();
		draw_julia(e);
		mlx_key_hook(e->win, key_hooks, e);
//		mlx_mouse_hook(e->win, mouse_hooks, e);
		mlx_loop(e->mlx);
	}
	return (0);
}