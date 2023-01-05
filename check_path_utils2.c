/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:29:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/05 14:37:50 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_struct(t_coords **new)
{
	free(*new);
	(*new) = NULL;
	return (-1);
}

int	create_coords(t_coords *end, t_coords **coords)
{
	(*coords) = ft_calloc(1, sizeof(t_coords));
	if (!(*coords))
		return (-1);
	(*coords)->endr = end->row;
	(*coords)->endc = end->col;
	return (0);
}

void	free_all(t_vars *vars, t_cell **cell_details, t_list *head, \
		t_coords *coords)
{
	int	row;

	row = 0;
	while (row < vars->row)
	{
		free(cell_details[row]);
		row++;
	}
	free(cell_details);
	ft_lstclear(&head, &free_coords);
	free(coords);
}
