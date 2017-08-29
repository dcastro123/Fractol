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

int			my_key_funct(int keycode)
{
	ft_putstr("Key Event: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == 53)
		exit(0);
	return (0);
}

// int			mouse_hooks(int keycode, t_env *e)
// {




// 	return (0);
// }

int			key_hooks(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	ft_putstr("keycode: ");
	ft_putendl(ft_itoa(keycode));
	e->x = 0;
	return (0);
}