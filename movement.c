/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:40:40 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/12 19:03:37 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_door(t_vars *vars)
{
	int	row;
	int	col;

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

void	get_player(t_vars *vars, t_coords *player)
{
	player->row = 1;
	player->col = 1;
	while ((vars->map)[player->row][player->col] != PLAYER)
	{
		while ((vars->map)[player->row][player->col] != PLAYER && \
				player->col < vars->col)
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
	else if ((vars->map)[row][col] == DOOR1)
		return (DOOR1);
	return (0);
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

int	movement(int keycode, t_vars *vars)
{
	int	move;

	if (keycode == ESC)
		destroy_all(vars);
	move = valid_move(vars, keycode);
	if (move == WALL || move == 0)
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
	ft_printf("MOVES: %i\n", vars->move_count);
	display_map(vars);
	return (0);
}
