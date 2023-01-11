/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:18:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/11 18:01:13 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_all(t_vars *vars)
{
	int	i;

	i = 7;
	while (vars->row--)
		free(vars->map[vars->row]);
	free(vars->map);
	free(vars->mapstr);
	if (vars->imgs != NULL)
	{
		while (i--)
			mlx_destroy_image(vars->mlx, vars->imgs[i]);
		free(vars->imgs);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	win(int move_count, t_vars *vars, int keycode)
{
	move_player(keycode, vars);
	display_map(vars);
	vars->collectible = -2;
	ft_printf("MOVES: %i\n", ++move_count);
	ft_printf("YOU WON!\n\nMOVES USED: %i\n", move_count);
	return (0);
}

int	check_win(t_vars *vars)
{
	if (vars->collectible == -2)
		destroy_all(vars);
	return (0);
}

void	game(t_vars *vars)
{
	t_coords	player;
	int			x;
	int			y;

	vars->mlx = mlx_init();
	if (create_images(vars))
	{
		ft_printf("Game error\n");
		destroy_all(vars);
	}
	get_player(vars, &player);
	vars->move_count = 0;
	vars->player = &player;
	x = vars->col;
	y = vars->row;
	if (x > 9)
		x = 9;
	if (y > 9)
		y = 9;
	vars->win = mlx_new_window(vars->mlx, x * 128, y * 128, "./so_long");
	display_map(vars);
	mlx_hook(vars->win, 17, 0, destroy_all, vars);
	mlx_key_hook(vars->win, movement, vars);
	mlx_loop_hook(vars->mlx, check_win, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		if (makemap(&vars, argv[1]))
		{
			ft_printf("Map error\n");
			return (-1);
		}
		game(&vars);
	}
	ft_printf("More or less than 1 map given\n");
	return (-1);
}
