/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 09:38:08 by upierre-          #+#    #+#             */
/*   Updated: 2017/05/18 18:24:40 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>
#include <unistd.h>

int		ligne(int xi, int yi, int xf, int yf, t_env *e)
{
	int		x;
	int		y;
	double	a;
	double	b;

	a = (double) (yf - yi) / (xf - xi);
	b = yi - a * xi ;
	x = 200;
	while(x == xi && x <= xf)
	{
		y = (int) (a * x + b);
		mlx_pixel_put(e->mlx, e->win, x, y, 0x00FF00FF);
		x++;
	}
	x = 0;
	y = 0;
/*	while(x <= 2000)
	{
		mlx_pixel_put(e->mlx, e->win, x, y, 0x00FF00FF);
		x++;
		y++;
		if ((x % 3) == 0)
			y--;
	}*/
	return(0);
}

int		my_key_funct(int keycode, t_env *e)
{
	int		x;
	int		y;
	int		xm;
	int		ym;

	x = 0;
	y = 0;	
	if (keycode == 124)
	{
		ym = y;
		while (y <= (ym + 10))
		{
			xm = x;
			while (x <= (xm + 10))
			{
				mlx_pixel_put(e->mlx, e->win, x, y, 0x00FF00FF);
				x++;
			}
			y++;
		}
	}
	if (keycode == 123)
	{
		ym = y;
		while (y <= (ym - 10))
		{
			xm = x;
			while (x <= (xm - 10))
			{
				mlx_pixel_put(e->mlx, e->win, x, y, 0x00010);
				x--;
			}
			y--;
		}
	}
	return(0);
}

int		gere_mouse(int button, int x, int y, void *param)
{
	printf("button event %d\n", button);
	(void)*param;
	ft_putstr("x = ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("y = ");
	ft_putnbr(y);
	ft_putchar('\n');
	return(0);
}

int		main()
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1500, 1000, "mlx 42");
	ligne(1, 1, 200, 200, &e);
	mlx_mouse_hook(e.win, gere_mouse, &e);
	mlx_key_hook(e.win, my_key_funct, &e);
	mlx_loop(e.mlx);
}
