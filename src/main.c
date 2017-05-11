/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upierre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 09:38:08 by upierre-          #+#    #+#             */
/*   Updated: 2017/05/11 14:39:13 by upierre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
//#include "../inc/fdf.h"
#include <stdio.h>

int		my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	if (keycode == 12)
		mlx_pixel_put(e->mlx, e->win, 50, 50, 0x00FFFFFF);
	(void)*param;
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
	void	*mlx;
	void	*window;
	int		x;
	int		y;
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(mlx, 400, 400, "mlx 42");
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
	mlx_key_hook(e.win, my_key_funct, &e);
//	mlx_mouse_hook(window, gere_mouse, &e);
	mlx_loop(mlx);
}
