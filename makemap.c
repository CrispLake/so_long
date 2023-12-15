/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:39:34 by emajuri           #+#    #+#             */
/*   Updated: 2023/12/15 14:49:29 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

static int	makestr(t_vars *vars, char *filename, long len)
{
	long	readval;
	int		fd;

	readval = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	vars->mapstr = malloc((len + 1) * sizeof(char));
	if (!vars->mapstr)
		return (-1);
	readval = read(fd, vars->mapstr, len);
	vars->mapstr[len] = '\0';
	if (readval < 0)
	{
		free(vars->mapstr);
		return (-1);
	}
	close(fd);
	return (0);
}

static int	maptostr(t_vars *vars, char *filename)
{
	int		fd;
	long	readval;
	char	buffer[BUFFER_SIZE];
	size_t	len;

	len = 0;
	readval = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-2);
	while (readval)
	{
		readval = read(fd, buffer, BUFFER_SIZE);
		if (readval < 0)
			return (-1);
		len += readval;
	}
	close(fd);
	if (makestr(vars, filename, len))
		return (-1);
	return (0);
}

int	print_error(void)
{
	ft_printf("Error\nInvalid filename\n");
	return (-1);
}

int	makemap(t_vars *vars, char *filename)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (print_error());
	if (ft_strncmp(dot, ".ber", 5))
	{
		ft_printf("Error\nMap's suffix is incorrect\n");
		return (-1);
	}
	if (maptostr(vars, filename))
	{
		ft_printf("Error\nInvalid filename/Permission denied\n");
		return (-1);
	}
	if (splitxy(vars->mapstr, '\n', vars))
		return (-1);
	if (validate(vars))
	{
		free(vars->map);
		free(vars->mapstr);
		return (-1);
	}
	return (0);
}
