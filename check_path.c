/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:28:04 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/16 18:53:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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
			cell_details[row][col].parent_col = -1;
			cell_details[row][col].parent_row = -1;
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
	cell_details = malloc(vars->row * sizeof(t_cell *));
	if (!cell_details)
		return (NULL);
	while (row < vars->row)
	{
		cell_details[row] = malloc(vars->col * sizeof(t_cell));
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

	new = malloc(sizeof(t_coords));
	if (!new)
		return (-1);
	new->row = own->row;
	new->col = own->col;
	new->f = f;
	*head = ft_lstnew(new);
	if (!*head)
		return (-1);
	return (0);
}

void	free_coords(void *own)
{
	free(own);
}

int	add_node(t_list **head, int f, int row, int col)
{
	t_coords	*new;
	t_list		*tmp;
	t_list		*ptr;

	new = malloc(sizeof(t_coords));
	if (!new)
		return (-1);
	new->row = row;
	new->col = col;
	new->f = f;
	tmp = ft_lstnew(new);
	if (!tmp)
		return (-1);
	if (*head == NULL || ((t_coords *)((*head)->content))->f >= f)
		ft_lstadd_front(head, tmp);
	else
	{
		ptr = *head;
		while (ptr->next != NULL && ((t_coords *)(ptr->next->content))->f < f)
			ptr = ptr->next;
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
	return (0);
}

void	print(t_cell **cell_details, t_vars *vars)
{
	int	row;
	int	col;

	row = 0;
	while (row < vars->row)
	{
		col = 0;
		while(col < vars->col)
		{
			if (cell_details[row][col].closed == 1)
				printf("2");
			else
				printf("%i", cell_details[row][col].closed);
			col++;
		}
		printf("\n");
		row++;
	}
	printf("\n");
}

int	a_star_search(t_vars *vars, t_coords *start, t_coords *end)
{
	t_cell		**cell_details;
	t_list		*head;
	t_list		*old_head;
	int			row;
	int			col;
	int			g;
	int			h;
	int			f;

	row = start->row;
	col = start->col;
	cell_details = create_2d_cells(vars);
	if (!cell_details)
		return (-1);
	cell_details[row][col].parent_row = row;
	cell_details[row][col].parent_col = col;
	if (create_open_list(&head, 0 + 0, start))
		return (-1);
	while (head != NULL)
	{
		row = ((t_coords *)(head->content))->row;
		col = ((t_coords *)(head->content))->col;
		old_head = head;
		head = head->next;
		ft_lstdelone(old_head, &free_coords);
		cell_details[row][col].closed = 1;
//1st successor
		if (is_valid(vars, row - 1, col))
		{
			if (row - 1 == end->row && col == end->col)
				return (0);
			else if (cell_details[row - 1][col].closed != 1 && vars->map[row - 1][col] != '1')
			{
				g = cell_details[row][col].g + 1;
				h = (row - 1 - end->row) + (col - end->col);
				f = g + h;
				if (cell_details[row - 1][col].f == F_MAX || cell_details[row - 1][col].f < f)
				{
					add_node(&head, f, row - 1, col);
					cell_details[row - 1][col].f = f;
					cell_details[row - 1][col].g = g;
					cell_details[row - 1][col].h = h;
					cell_details[row - 1][col].parent_row = row;
					cell_details[row - 1][col].parent_col = col;
				}
			}
		}
//		print(cell_details, vars);
//2nd
		if (is_valid(vars, row + 1, col))
		{
			if (row + 1 == end->row && col == end->col)
				return (0);
			else if (cell_details[row + 1][col].closed != 1 && vars->map[row + 1][col] != '1')
			{
				g = cell_details[row][col].g + 1;
				h = (row + 1 - end->row) + (col - end->col);
				f = g + h;
				if (cell_details[row + 1][col].f == F_MAX || cell_details[row + 1][col].f < f)
				{
					add_node(&head, f, row + 1, col);
					cell_details[row + 1][col].f = f;
					cell_details[row + 1][col].g = g;
					cell_details[row + 1][col].h = h;
					cell_details[row + 1][col].parent_row = row;
					cell_details[row + 1][col].parent_col = col;
				}
			}
		}
//		print(cell_details, vars);
//3rd
		if (is_valid(vars, row, col - 1))
		{
			if (row == end->row && col - 1 == end->col)
				return (0);
			else if (cell_details[row][col - 1].closed != 1 && vars->map[row][col - 1] != '1')
			{
				g = cell_details[row][col].g + 1;
				h = (row - end->row) + (col - 1 - end->col);
				f = g + h;
				if (cell_details[row][col - 1].f == F_MAX || cell_details[row][col - 1].f < f)
				{
					add_node(&head, f, row, col - 1);
					cell_details[row][col - 1].f = f;
					cell_details[row][col - 1].g = g;
					cell_details[row][col - 1].h = h;
					cell_details[row][col - 1].parent_row = row;
					cell_details[row][col - 1].parent_col = col;
				}
			}
		}
//		print(cell_details, vars);
//4th
		if (is_valid(vars, row, col + 1))
		{
			if (row == end->row && col + 1 == end->col)
				return (0);
			else if (cell_details[row][col + 1].closed != 1 && vars->map[row][col + 1] != '1')
			{
				g = cell_details[row][col].g + 1;
				h = (row - end->row) + (col - 1 - end->col);
				f = g + h;
				if (cell_details[row][col + 1].f == F_MAX || cell_details[row][col + 1].f < f)
				{
					add_node(&head, f, row, col + 1);
					cell_details[row][col + 1].f = f;
					cell_details[row][col + 1].g = g;
					cell_details[row][col + 1].h = h;
					cell_details[row][col + 1].parent_row = row;
					cell_details[row][col + 1].parent_col = col;
				}
			}
		}
		print(cell_details, vars);
	}
	return (-1);
}

void	find_coords(t_vars *vars, t_coords **coords)
{
	int	row;
	int col;
	int i;

	i = 0;
	row = 0;
	*coords = malloc(vars->collectible + 3 * sizeof(t_coords));
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
		if (a_star_search(vars, &coords[i], &coords[i + 1]))
		{
			i = vars->collectible + 2;
			while (i-- >= 0)
				free(coords + i);
			free(coords);
			return (-1);
		}
		coords++;
	}
	return (0);
}
