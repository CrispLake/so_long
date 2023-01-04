/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star_successors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:02:53 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/04 17:48:02 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	successor_north(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details)
{
	int	g;
	int	h;

	if (is_valid(vars, coords->row - 1, coords->col))
	{
		if (coords->row - 1 == coords->endr && coords->col == coords->endc)
			return (1);
		else if (cell_details[coords->row - 1][coords->col].closed != 1
				&& vars->map[coords->row - 1][coords->col] != '1')
		{
			g = cell_details[coords->row][coords->col].g + 1;
			h = (coords->row - 1 - coords->endr) + (coords->col - coords->endc);
			if (h < 0)
				h = -h;
			if (cell_details[coords->row - 1][coords->col].f == F_MAX
					|| cell_details[coords->row - 1][coords->col].f < g + h)
			{
				add_node(head, g + h, coords->row - 1, coords->col);
				cell_details[coords->row - 1][coords->col].f = g + h;
				cell_details[coords->row - 1][coords->col].g = g;
				cell_details[coords->row - 1][coords->col].h = h;
			}
		}
	}
	return (0);
}

int	successor_south(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details)
{
	int	g;
	int	h;

	if (is_valid(vars, coords->row + 1, coords->col))
	{
		if (coords->row + 1 == coords->endr && coords->col == coords->endc)
			return (1);
		else if (cell_details[coords->row + 1][coords->col].closed != 1
				&& vars->map[coords->row + 1][coords->col] != '1')
		{
			g = cell_details[coords->row][coords->col].g + 1;
			h = (coords->row + 1 - coords->endr) + (coords->col - coords->endc);
			if (h < 0)
				h = -h;
			if (cell_details[coords->row + 1][coords->col].f == F_MAX
					|| cell_details[coords->row + 1][coords->col].f < g + h)
			{
				add_node(head, g + h, coords->row + 1, coords->col);
				cell_details[coords->row + 1][coords->col].f = g + h;
				cell_details[coords->row + 1][coords->col].g = g;
				cell_details[coords->row + 1][coords->col].h = h;
			}
		}
	}
	return (0);
}

int	successor_west(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details)
{
	int	g;
	int	h;

	if (is_valid(vars, coords->row, coords->col - 1))
	{
		if (coords->row == coords->endr && coords->col - 1 == coords->endc)
			return (1);
		else if (cell_details[coords->row][coords->col - 1].closed != 1
				&& vars->map[coords->row][coords->col - 1] != '1')
		{
			g = cell_details[coords->row][coords->col].g + 1;
			h = (coords->row - coords->endr) + (coords->col - 1 - coords->endc);
			if (h < 0)
				h = -h;
			if (cell_details[coords->row][coords->col - 1].f == F_MAX
					|| cell_details[coords->row][coords->col - 1].f < g + h)
			{
				add_node(head, g + h, coords->row, coords->col - 1);
				cell_details[coords->row][coords->col - 1].f = g + h;
				cell_details[coords->row][coords->col - 1].g = g;
				cell_details[coords->row][coords->col - 1].h = h;
			}
		}
	}
	return (0);
}

int	successor_east(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details)
{
	int	g;
	int	h;

	if (is_valid(vars, coords->row, coords->col + 1))
	{
		if (coords->row == coords->endr && coords->col + 1 == coords->endc)
			return (1);
		else if (cell_details[coords->row][coords->col + 1].closed != 1
				&& vars->map[coords->row][coords->col + 1] != '1')
		{
			g = cell_details[coords->row][coords->col].g + 1;
			h = (coords->row - coords->endr) + (coords->col + 1 - coords->endc);
			if (h < 0)
				h = -h;
			if (cell_details[coords->row][coords->col + 1].f == F_MAX
					|| cell_details[coords->row][coords->col + 1].f < g + h)
			{
				add_node(head, g + h, coords->row, coords->col + 1);
				cell_details[coords->row][coords->col + 1].f = g + h;
				cell_details[coords->row][coords->col + 1].g = g;
				cell_details[coords->row][coords->col + 1].h = h;
			}
		}
	}
	return (0);
}

int	add_node(t_list **head, int f, int row, int col)
{
	t_coords	*new;
	t_list		*tmp;
	t_list		*ptr;

	new = ft_calloc(1, sizeof(t_coords));
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
