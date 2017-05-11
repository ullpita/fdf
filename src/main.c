/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 09:38:08 by upierre-          #+#    #+#             */
/*   Updated: 2017/05/11 16:38:09 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>
#include <unistd.h>

int		my_key_funct(int keycode, t_env *e)
{
	printf("key event %d\n", keycode);
	if (keycode == 12)
		mlx_pixel_put(e->mlx, e->win, 200, 200, 0x00FF00FF);
	if (keycode == 13)
		mlx_pixel_put(e->mlx, e->win, 325, 325, 0x00FF00FF);
	return(0);
}
/*
int		gere_mouse(int button, int x, int y, void *param)
{
	printf("you touched the target %d", button);
	(void)*param;
	(void)x;
	(void)y;
	return(0);
}*/

int		main()
{
	int		x;
	int		y;
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 400, 400, "mlx 42");
	y = 125;
	while(y <= 275) 
	{
		x = 125;
		while(x < 275)
		{
			mlx_pixel_put(e.mlx, e.win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_pixel_put(e.mlx, e.win, 75, 75, 0x00FF00FF);
	mlx_key_hook(e.win, my_key_funct, &e);
//	mlx_mouse_hook(window, gere_mouse, &e);
	mlx_loop(e.mlx);
}
