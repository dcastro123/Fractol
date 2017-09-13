/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:36:06 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/13 01:49:07 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	controls(void)
{
	ft_putendl("CONTROLS:\n");
	ft_putendl("Zoom In/Out: Mousewheel Up/Down\n");
	ft_putendl("Increase/Decrease Iteration: Keypad plus/minus\n");
	ft_putendl("Add/Remove color: z/c\n");
	ft_putendl("Lock screen: Space\n");
	ft_putendl("Unlock screen: Enter\n");
}

void	display_opts(void)
{
	ft_putendl("Usage: ./fractol [option number]");
	ft_putstr("Valid Options:\n\
		1: Julia\n\
		2: Mandlebrot\n\
		3. WIP\n");
}

void	get_opt(char s, t_env *e)
{
	if (s == '1')
		e->choice = 1;
	else if (s == '2')
		e->choice = 2;
	else if (s == '3')
		e->choice = 3;
}
