/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 18:06:07 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/01 16:43:41 by dcastro-         ###   ########.fr       */
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
#include <stdio.h>
#include <pthread.h>

# define WINDOW_H	1000
# define WINDOW_W	1000
# define zoom		1.1
# define SQR(x)		(x * x)

# define K_UP  		126
# define K_DWN 		125
# define K_LFT 		123
# define K_RHT 		124
# define K_SPCE 	49
# define K_PLUS 	24
# define K_MIN 		27
# define K_ESC 		53

# define WHITE		0xf8f8ff
# define BLACK		0x0
typedef struct			s_env
{
	char	*name;
	int	x;
	void	*mlx;
	void	*win;
	int		max;
	int		*colors;
	double	zr;
	double	zi;
	double	ci;
	double	cr;
	int		xtrans;
	int		ytrans;
}						t_env;

int			key_hooks(int keycode, t_env *e);
int			my_key_funct(int keycode);

void	draw_mandle(t_env *e);
#endif
