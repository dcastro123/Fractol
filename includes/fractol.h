/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 18:06:07 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/08 21:11:39 by dcastro-         ###   ########.fr       */
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

# define K_PLUS		0X45
# define K_MINUS   	0X4E
# define K_ESC		0X35

# define M_LCLICK	0x01
# define M_RCLICK	0x02
# define M_UPSCRLL	0x04
# define M_DWNSCRLL	0x05

# define WHITE		0xf8f8ff
# define BLACK		0x0

# define SQR(x)		(x * x)

typedef struct			s_env
{
	char	*image;
	int		*data;
	char	*name;
	int	x;
	void	*mlx;
	void	*win;
	int		max;
	int		bits;
	int		size;
	int		end;
	double	zr;
	double	zi;
	double	ci;
	double	cr;
	double		xtrans;
	double		ytrans;
	double		zoom;
}						t_env;

typedef	struct 			s_rgb 
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}						t_rgb;

int			key_hooks(int keycode, t_env *e);
int			mouse_hooks(int x, int y, int keycode, t_env *e);

void	draw_fract(t_env *e);
void	draw_mandle(t_env *e);
void	draw_julia(t_env *e);
#endif
