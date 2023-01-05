/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:14:32 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/05 13:16:42 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(t_vars *vars, int row, int col)
{
	if (vars->map[row][col] == '1')
		return (0);
	return (1);
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
			cell_details[row][col].closed = 0;
			cell_details[row][col].f = F_MAX;
			cell_details[row][col].g = 0;
			cell_details[row][col].h = 0;
			col++;
		}
		row++;
	}
}

t_cell	**create_2d_cells(t_vars *vars)
{
	int		row;
	t_cell	**cell_details;

	row = 0;
	cell_details = ft_calloc(vars->row, sizeof(t_cell *));
	if (!cell_details)
		return (NULL);
	while (row < vars->row)
	{
		cell_details[row] = ft_calloc(vars->col, sizeof(t_cell));
		if (!cell_details[row])
		{
			while (row-- >= 0)
				free(cell_details[row]);
			free(cell_details);
			return (NULL);
		}
		row++;
	}
	zero_2d_cells(cell_details, vars);
	return (cell_details);
}

int	create_open_list(t_list **head, int f, t_coords *own)
{
	t_coords	*new;

	new = ft_calloc(1, sizeof(t_coords));
	if (!new)
		return (-1);
	new->row = own->row;
	new->col = own->col;
	new->f = f;
	*head = ft_lstnew(new);
	if (!*head)
	{
		free(new);
		return (-1);
	}
	return (0);
}

void	free_coords(void *own)
{
	free(own);
}
