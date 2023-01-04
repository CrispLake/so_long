/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:28:04 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/04 18:08:53 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_coords(t_coords *end, t_coords **coords)
{
	(*coords) = ft_calloc(1, sizeof(t_coords));
	if (!(*coords))
		return (-1);
	(*coords)->endr = end->row;
	(*coords)->endc = end->col;
	return (0);
}

int	search(t_vars *vars, t_cell **cell_details, t_list *head, t_coords *end)
{
	t_coords	*coords;
	t_list		*old_head;

	if (create_coords(end, &coords))
		return (-1);
	while (head != NULL)
	{
		coords->row = ((t_coords *)(head->content))->row;
		coords->col = ((t_coords *)(head->content))->col;
		old_head = head;
		head = head->next;
		ft_lstdelone(old_head, &free_coords);
		cell_details[coords->row][coords->col].closed = 1;
		if (successor_north(vars, coords, &head, cell_details))
			return (0);
		if (successor_south(vars, coords, &head, cell_details))
			return (0);
		if (successor_west(vars, coords, &head, cell_details))
			return (0);
		if (successor_east(vars, coords, &head, cell_details))
			return (0);
	}
	return (-1);
}

int	a_star_search(t_vars *vars, t_coords *start, t_coords *end)
{
	t_cell		**cell_details;
	t_list		*head;
	int			row;
	int			col;

	row = start->row;
	col = start->col;
	cell_details = create_2d_cells(vars);
	if (!cell_details)
		return (-1);
	if (create_open_list(&head, 0, start))
		return (-1);
	if (search(vars, cell_details, head, end))
		return (-1);
	return (0);
}

void	find_coords(t_vars *vars, t_coords **coords)
{
	int	row;
	int	col;
	int	i;

	i = 0;
	row = 0;
	*coords = ft_calloc(vars->collectible + 3, sizeof(t_coords));
	if (!coords)
		return ;
	(*coords)[vars->collectible + 2].row = -1;
	while (row < vars->row)
	{
		col = 0;
		while (col < vars->col)
		{
			if (vars->map[row][col] == 'C' || vars->map[row][col] == 'E' ||
					vars->map[row][col] == 'P')
			{
				(*coords)[i].row = row;
				(*coords)[i++].col = col;
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
	while (coords[i + 1].row != -1)
	{
		if (a_star_search(vars, &(coords[i]), &(coords[i + 1])))
		{
			free(coords);
			return (-1);
		}
		i++;
	}
	return (0);
}
