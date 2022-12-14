/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:28:04 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/14 19:20:31 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(char **coordinate)
{
	if (**coordinate == '1')
		return (0);
	return (1);
}

int	create_2d_array(char **array, t_vars *vars)
{
	int	row;

	row = 0;
	array = ft_calloc(vars->row, sizeof(char *));
	if (!array)
		return (-1);
	while (row < vars->col)
	{
		array[row] = ft_calloc(vars->col, sizeof(char));
		if (!array[row])
		{
			while (row-- >= 0)
				free(array[row]);
			free(array);
			return (-1);
		}
		row++;
	}
	return (0);
}

void	zero_2d_cells(t_cell **cell_details, t_vars *vars)
{
	int	row;
	int	col;

	row = 0;
	while (row < vars->row)
	{
		col = 0;
		while (col < vars->col)
		{
			cell_details[row][col].f = 0;
			cell_details[row][col].g = 0;
			cell_details[row][col].h = 0;
			cell_details[row][col].parent_col = -1;
			cell_details[row][col].parent_row = -1;
			col++;
		}
		row++;
	}
}

int	create_2d_cells(t_cell **cell_details, t_vars *vars)
{
	int	row;
	
	row = 0;
	cell_details = malloc(vars->row * sizeof(t_cell *));
	if (!cell_details)
		return (-1);
	while (row < vars->row)
	{
		cell_details[row] = malloc(vars->col * sizeof(t_cell));
		if (!cell_details[row])
		{
			while (row-- >= 0)
				free(cell_details[row]);
			free(cell_details);
			return (-1);
		}
		row++;
	}
	zero_2d_cells(cell_details, t_vars *vars);
	return (0);
}

int	a_star_search(t_vars *vars, t_coords start, t_coords end)
{
	char		**closed_list;
	t_cell		**cell_details;

	if (create_2d_array(closed_list, vars))
		return (-1);
	if (create_2d_cells(cell_details, vars))
	{
		return (-1);
	}
}

void	find_coords(t_vars *vars, t_coords **coords)
{
	int	row;
	int col;
	int i;

	i = 0;
	row = 0;
	col = 0;
	coords = malloc(vars->collectible + 3 * sizeof(t_coords));
	if (!coords)
		return ;
	coords[vars->collectible + 2] = NULL;
	while (row < vars->row)
	{
		while (col < vars->col)
		{
			if (vars->map[row][col] == 'C' || vars->map[row][col] == 'E'
					vars->map[row][col] == 'P')
			{
				coords[i].row = row;
				coords[i++].col = col;
			}
			col++;
		}
		row++;
	}
}

int	check_path(t_vars *vars)
{
	t_coords	*coords;
	int			i;

	i = 0;
	find_coords(vars, &coords);
	if (!coords)
		return (-1);
	while (coords[i + 1] != NULL)
	{
		if (a_star_search(vars, coords[i], coords[i + 1]))
		{
			i = vars->collectible + 2;
			while (i-- >= 0)
				free(coords[i]);
			free(coords);
			return (-1);
		}
		coords++;
	}
	return (0);
}
