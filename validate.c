/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:09:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/04 17:47:24 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(t_vars *vars)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (col < vars->col)
	{
		if (vars->map[0][col] != '1' || vars->map[vars->row - 1][col] != '1')
			return (-1);
		col++;
	}
	while (row < vars->row)
	{
		if (vars->map[row][0] != '1' || vars->map[row][vars->col - 1] != '1')
			return (-1);
		row++;
	}
	return (0);
}

static int	check_chars(t_vars *vars, int i, int exit, int player)
{
	int	space;

	space = 0;
	vars->collectible = 0;
	while (vars->mapstr[i])
	{
		if (vars->mapstr[i] == 'C')
			vars->collectible++;
		else if (vars->mapstr[i] == 'E')
			exit++;
		else if (vars->mapstr[i] == 'P')
			player++;
		else if (vars->mapstr[i] == '0')
			space++;
		else if (vars->mapstr[i] != '1' && vars->mapstr[i] != '\n')
			return (-1);
		i++;
	}
	if (player != 1 || exit != 1 || vars->collectible < 1 || space < 1)
		return (-1);
	return (0);
}

int	validate(t_vars *vars)
{
	if (check_walls(vars))
		return (-1);
	if (check_chars(vars, 0, 0, 0))
		return (-1);
	if (check_path(vars))
		return (-1);
	return (0);
}
