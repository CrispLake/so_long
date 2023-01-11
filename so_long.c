/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:18:48 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/11 13:28:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include <stdio.h>

int	destroy_all(t_vars *vars)
{
	int	i;

	i = 8;
	while(vars->row--)
		free(vars->map[vars->row]);
	free(vars->map);
	free(vars->mapstr);
	while (i--)
		mlx_destroy_image(vars->mlx, vars->imgs[i]);
	free(vars->imgs);
	mlx_destroy_window(vars->mlx, vars->win);
	system("export MallocStackLogging=1");
	system("leaks so_long");
	exit(0);
}

void	get_player(t_vars *vars, t_coords *player)
{
	player->row = 1;
	player->col = 1;
	while ((vars->map)[player->row][player->col] != PLAYER)
	{
		while ((vars->map)[player->row][player->col] != PLAYER && player->col < vars->col)
			player->col++;
		if ((vars->map)[player->row][player->col] != PLAYER)
		{
			player->col = 1;
			player->row++;
		}
	}
}

int	valid_move(t_vars *vars, int move)
{
	int	row;
	int	col;

	row = (vars->player)->row;
	col = (vars->player)->col;
	if (move == W || move == UP)
		row--;
	else if (move == A || move == LEFT)
		col--;
	else if (move == S || move == DOWN)
		row++;
	else if (move == D || move == RIGHT)
		col++;
	if ((vars->map)[row][col] == WALL)
		return (WALL);
	else if ((vars->map)[row][col] == SPACE)
		return (SPACE);
	else if ((vars->map)[row][col] == COIN)
		return (COIN);
	else if ((vars->map)[row][col] == DOOR0)
		return (DOOR0);
	return (DOOR1);
}

void	move_player(int keycode, t_vars *vars)
{
	int	*row;
	int	*col;

	row = &(vars->player)->row;
	col = &(vars->player)->col;
	if ((vars->map)[*row][*col] != DOOR2)
		(vars->map)[*row][*col] = SPACE;
	else
		(vars->map)[*row][*col] = DOOR0;
	if (keycode == W || keycode == UP)
		(*row)--;
	else if (keycode == A || keycode == LEFT)
		(*col)--;
	else if (keycode == S || keycode == DOWN)
		(*row)++;
	else if (keycode == D || keycode == RIGHT)
		(*col)++;
	if ((vars->map)[*row][*col] == SPACE || (vars->map)[*row][*col] == COIN)
		(vars->map)[*row][*col] = PLAYER;
	else if ((vars->map)[*row][*col] == DOOR0)
		(vars->map)[*row][*col] = DOOR2;
	else
		(vars->map)[*row][*col] = DOOR3;
}

void	put_image(t_vars *vars, int row, int col)
{
	int	i;
	char c;

	c = (vars->map)[row][col];
	if (c == SPACE)
		i = SPACE_IMG;
	else if (c == WALL)
		i = WALL_IMG;
	else if (c == COIN)
		i = COIN_IMG;
	else if (c == PLAYER)
		i = PLAYER_IMG;
	else if (c == DOOR0)
		i = DOOR0_IMG;
	else if (c == DOOR1)
		i = DOOR1_IMG;
	else if (c == DOOR2)
		i = DOOR2_IMG;
	else
		i = DOOR3_IMG;
	mlx_put_image_to_window(vars->mlx, vars->win, (vars->imgs)[i], vars->x * 128, vars->y * 128);
}

void	set_row_col(t_vars *vars, int *row, int *col)
{
	if (vars->row > 9)
	{
		*row = (vars->player)->row;
		while (*row < 8)
			(*row)++;
		while (*row < (vars->player)->row + 4 && *row < vars->row - 1)
			(*row)++;
	}
	else
		*row = vars->row - 1;
	if (vars->col > 9)
	{
		*col = (vars->player)->col;
		while (*col < 8)
			(*col)++;
		while (*col < (vars->player)->col + 4 && *col < vars->col - 1)
			(*col)++;
	}
	else
		*col = vars->col - 1;
}

void	set_xy(t_vars *vars)
{
	if (vars->row > 9)
		vars->y = 8;
	else
		vars->y = vars->row - 1;
	if (vars->col > 9)
		vars->x = 8;
	else
		vars->x = vars->col - 1;
}

void	display_map(t_vars *vars)
{
	int	row;
	int	col;
	int	colsave;
	int	xsave;

	set_row_col(vars, &row, &col);
	set_xy(vars);
	xsave = vars->x;
	colsave = col;
	while (vars->y >= 0)
	{
		vars->x = xsave;
		col = colsave;
		while (vars->x >= 0)
		{
			put_image(vars, row, col);
			(vars->x)--;
			col--;
		}
		(vars->y)--;
		row--;
	}
}

int	win(int move_count, t_vars *vars, int keycode)
{
	move_player(keycode, vars);
	display_map(vars);
	vars->collectible = -2;
	printf("YOU WON!\n\nMOVES USED: %i\n", move_count);
	return (0);
}

void	open_door(t_vars *vars)
{
	int	row;
	int col;

	row = 1;
	col = 1;
	while ((vars->map)[row][col] != DOOR0)
	{
		while ((vars->map)[row][col] != DOOR0 && col < vars->col)
			col++;
		if ((vars->map)[row][col] != DOOR0)
		{
			col = 1;
			row++;
		}
	}
	(vars->map)[row][col] = DOOR1;
	vars->collectible--;
}

int	movement(int keycode, t_vars *vars)
{
	int	move;

	if (keycode == ESC)
		destroy_all(vars);
	move = valid_move(vars, keycode);
	if (move == WALL)
		return (0);
	else if (move == SPACE)
		move_player(keycode, vars);
	else if (move == COIN)
	{
		vars->collectible--;
		move_player(keycode, vars);
	}
	else if (move == DOOR0)
		move_player(keycode, vars);
	else if (move == DOOR1)
			return (win(vars->move_count, vars, keycode));
	if (!vars->collectible)
		open_door(vars);
	vars->move_count++;
	printf("MOVES: %i\n", vars->move_count);
	display_map(vars);
	return (0);
}

int create_images(t_vars *vars)
{
	int x;
	int y;

	vars->imgs = ft_calloc(8, sizeof(void *));
	if (vars->imgs == NULL)
		return (-1);
	vars->imgs[SPACE_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/space.xpm", &x, &y);
	vars->imgs[WALL_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/meteorite.xpm", &x, &y);
	vars->imgs[COIN_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/coin.xpm", &x, &y);
	vars->imgs[PLAYER_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/player.xpm", &x, &y);
	vars->imgs[DOOR0_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/door0.xpm", &x, &y);
	vars->imgs[DOOR1_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/door1.xpm", &x, &y);
	vars->imgs[DOOR2_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/door2.xpm", &x, &y);
	vars->imgs[DOOR3_IMG] = mlx_xpm_file_to_image(vars->mlx, \
			"./images/door3.xpm", &x, &y);
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
		return ;
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
			printf("Map error\n");
			return (-1);
		}
		game(&vars);
		printf("Game error\n");
		return (-1);
	}
	printf("More or less than 1 map given\n");
	return (-1);
}
