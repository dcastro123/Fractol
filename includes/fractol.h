/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <dcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 18:06:07 by dcastro-          #+#    #+#             */
/*   Updated: 2017/09/13 22:47:31 by dcastro-         ###   ########.fr       */
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

# define THREAD_COUNT	15
# define WINDOW_H		1000
# define WINDOW_W		1000
# define WIN_WSPLIT		(WINDOW_W / 2)
# define WIN_HSPLIT		(WINDOW_H / 2)
# define ZOOM_SCALE		0.90

# define K_PLUS			0X45
# define K_MINUS   		0X4E
# define K_ESC			0X35
# define K_SPCE			0x31
# define K_ENT			0x24

# define M_LCLICK		0x01
# define M_RCLICK		0x02
# define M_UPSCRLL		0x04
# define M_DWNSCRLL		0x05

# define WHITE			0xf8f8ff
# define BLACK			0x0

# define SQR(x)			(x * x)

typedef struct			s_env
{
	int		*color_arr;
	char	*image;
	int		*data;
	void	*mlx;
	void	*win;
	int		choice;
	int		max;
	int		bits;
	int		size;
	int		end;
	int		flag;
	double	zr;
	double	zi;
	double	ci;
	double	cr;
	double	mouse_x;
	double	mouse_y;
	double	xdist;
	double	ydist;
	double		xtrans;
	double		ytrans;
	double		zoom;
	unsigned int	r;
	unsigned	int	g;
	unsigned	int	b;
}						t_env;

typedef struct s_ptr
{
	t_env *en;
	int	i;
	int	i_lim;
}				t_ptr;

void		controls(void);
void		display_opts(void);
void		get_opt(char s, t_env *e);

int			key_hooks(int keycode, t_env *e);
int			mouse_hooks(int x, int y, int keycode, t_env *e);
int			julia_mouse_hook(int x, int y, t_env *e);

void		draw_fract(t_env *e);
void		draw_mandel(t_env *e);
void		draw_julia(t_env *e);
void		draw_ship(t_env *e);
void		draw_clover(t_env *e);
#endif
