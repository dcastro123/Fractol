/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:20:46 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/08 21:16:32 by dcastro-         ###   ########.fr       */
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
		e->name = ft_strdup("error");
	printf("name store: %s\n", e->name);
}

static	void	controls(void)
{
	ft_putendl("CONTROLS:\n");
	ft_putendl("Zoom In/Out: Mousewheel Up/Down\n");
	ft_putendl("Increase/Decrease Iteration: Keypad plus/minus\n");
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
		draw_fract(e);
		controls(); 
		mlx_key_hook(e->win, key_hooks, e);
		mlx_mouse_hook(e->win, mouse_hooks, e);
		mlx_loop(e->mlx);
	}
	return (0);
}