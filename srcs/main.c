/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:20:46 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/21 17:33:52 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	display_opts(void)
{
	ft_putendl("Usage: ./fdf [option number]");
	ft_putstr("Valid Options:\n\
		1: Julia\n\
		2: Mandlebrot\n");
}

int	main(int ac, char **av)
{
	t_env *e;

	if (!(e = ft_memalloc(sizeof(t_env))))
		return (NULL);
	if (ac != 2)
		ft_putendl("Wrong Number of Arguments");
	else
	{
		display_opts();
		init_env(e);
	}
}