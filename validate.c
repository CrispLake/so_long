/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:09:28 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/12 17:33:14 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_walls(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x;
	y = vars->y;
	while (x > 0)
	{
		x--;
		if (vars->map[0][x] != '1' || vars->map[y - 1][x] != '1')
			return (-1);
	}
	while (y > 0)
	{
		y--;
		if (vars->map[y][0] != '1' || vars->map[y][vars->x - 1] != '1')
			return (-1);
	}
	return (0);
}

static int	check_chars(t_vars *vars)
{
	int	i;
	int	exit;
	int	player;

	i = 0;
	exit = 0;
	player = 0;
	vars->collectible = 0;
	while (vars->mapstr[i])
	{
		if (vars->mapstr[i] == 'C')
			vars->collectible++;
		else if (vars->mapstr[i] == 'E')
			exit++;
		else if (vars->mapstr[i] == 'P')
			player++;
		else if (vars->mapstr[i] != '1' && vars->mapstr[i] != '0' &&
				vars->mapstr[i] != '\n')
			return (-1);
		i++;
	}
	if (player != 1 || exit != 1 || vars->collectible < 1)
		return (-1);
	return (0);
}

int	check_path(t_vars *vars)
{
	

}

int	validate(t_vars *vars)
{
	if (check_walls(vars))
	{
		free(vars->map);
		free(vars->mapstr);
		return (-1);
	}
	if (check_chars(vars))
	{
		free(vars->map);
		free(vars->mapstr);
		return (0);
	}
	return (0);
}
