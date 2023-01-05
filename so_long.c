/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:18:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/05 17:20:18 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	i = 0;
	if (argc == 2)
	{
		if (makemap(&vars, argv[1]))
		{
			printf("Map error\n");
			return (-1);
		}
		while (vars.row)
		{
			printf("%s\n", vars.map[i]);
			i++;
			vars.row--;
		}
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 960, 520, "Hello world!");
		vars.img = mlx_new_image(mlx, 960, 520);
		vars.img = mlx_xpm_file_to_image(vars.mlx, "./images/player.xpm", &vars.x, &vars.y);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
		mlx_loop(vars.mlx);
		printf("Bye!");
		return (0);
	}
	printf("More or less than 1 map given\n");
	return (-1);
}
