/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:55:09 by emajuri           #+#    #+#             */
/*   Updated: 2023/04/04 15:14:52 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_error(t_vars *vars)
{
	int	i;

	i = 0;
	while (i <= DOOR3_IMG)
	{
		if (vars->imgs[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}
