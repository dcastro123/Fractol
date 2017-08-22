/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 18:06:07 by dcastro-          #+#    #+#             */
/*   Updated: 2017/08/21 17:45:12 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

#include "../libft/inc/libft.h"
#include "../minilibx_macos/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

# define WINDOW_H	768
# define WINDOW_W	1366

# define K_UP  		126
# define K_DWN 		125
# define K_LFT 		123
# define K_RHT 		124
# define K_SPCE 	49
# define K_PLUS 	24
# define K_MIN 		27
# define K_ESC 		53

typdef struct			s_env
{
	char	*name;
}						t_env;


