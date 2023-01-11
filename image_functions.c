/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:55:00 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/11 17:21:12 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_vars *vars, int row, int col)
{
	int		i;
	char	c;

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
	mlx_put_image_to_window(vars->mlx, vars->win, \
			(vars->imgs)[i], vars->x * 128, vars->y * 128);
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

int	create_images(t_vars *vars)
{
	int	x;
	int	y;

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
