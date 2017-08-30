/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:51:47 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/25 19:45:18 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
*	Formula for drawing the Mandlebrot set of Fractals
**/
/*
** z.r = 0;
z.i = 0;
zrsqr = z.r * z.r;
zisqr = z.i * z.i;
while (zrsqr + zisqr <= 4.0)
{
z.i = square(z.r + z.i) – zrsqr – zisqr;
z.i += c.i;
z.r = zrsqr – zisqr + c.r;
zrsqr = square(z.r);
zisqr = square(z.i);
}
*/
