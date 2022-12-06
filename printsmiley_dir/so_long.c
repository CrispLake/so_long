/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:18:48 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/06 17:11:14 by emajuri          ###   ########.fr       */
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		color = 0x000000FF;
	int		x = 0;
	int 	y;
	int		z;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	while (x < 200)
	{
		y = 2*sqrt(4*x);
		z = 0;
		while (z < 6)
		{
			if (z == 2 || z == 4)
				color = color << 8;	
			my_mlx_pixel_put(&img, 850 + x, 500 + y + z, color);
			z++;
		}
		color = color >> 16;
		z = 0;
		while (z < 6)
		{
			if (z == 2 || z == 4)
				color = color << 8;	
			my_mlx_pixel_put(&img, 1249 - x, 500 + y + z, color);
			z++;
		}
		color = color >> 16;
		x++;
	}
	drawCircle(40, img, 950, 420, 0x00FF0000);
	drawCircle(40, img, 1150, 420, 0X0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
