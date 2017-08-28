/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:20:46 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/25 19:44:25 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	display_opts(void)
{
	ft_putendl("Usage: ./fractol [option number]");
	ft_putstr("Valid Options:\n\
		1: Julia\n\
		2: Mandlebrot\n");
}

static	void	get_opt(char s, t_env *e)
{
	if (s == '1')
		e->name = ft_strdup("Julia");
	else if (s == '2')
		e->name = ft_strdup("Mandlebrot");
}

static	void	controls(void)
{
	ft_putendl("CONTROLS:");
	ft_putendl("Move: W: up A: left S: down D: right")
	ft_putendl("Zoom In/Out: Mousewheel Up/Down");
	ft_putendl("Increase/Decrease Iteration: Up Arrow/Down Arrow");
	ft_putendl("Add/Remove color: z/c");
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
		//setup_env(e);
		controls();
		//draw(e);
	}
	return (0);
}