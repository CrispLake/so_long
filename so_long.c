/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:18:48 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/06 18:48:03 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void drawCircle(int r, t_data img, int mx, int my, int color)
{
    // Consider a rectangle of size N*N
    int N = 2*r+1;
 
    int x, y;  // Coordinates inside the rectangle
	int z = 5004;
 
    // Draw a square of size N*N.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Start from the left most corner point
            x = i-r;
            y = j-r;
 
            // If this point is inside the circle, print it
            if (x*x + y*y <= r*r+1)
			{
				my_mlx_pixel_put(&img, mx + x, my + y, color);
				if (z % 3 == 2)
					color = 0x0000FF00;
				else if (z % 3 == 0)
					color = 0x000000FF;
				else if (z % 3 == 1)
					color = 0x00FF0000;
				z++;
			}
			z = 3 * z + 1;
			z *= 2;
		}
    }
}

#include <stdio.h>

int	print_circles(int keycode, t_vars *vars)
{
	t_data	img;
	static int	x = 0;
	static int	y = 0;

	printf("%i\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	else if (keycode == W)
		y -= 15;
	else if (keycode == A)
		x -= 15;
	else if (keycode == S)
		y += 15;
	else if (keycode == D)
		x += 15;
	img.img = mlx_new_image(vars->mlx, 960, 520);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	drawCircle(40, img, 480 + x, 260 + y, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 960, 520, "Hello world!");
	mlx_hook(vars.win, 2, 1L, print_circles, &vars);
	mlx_loop(vars.mlx);
}
