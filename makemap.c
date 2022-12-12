/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:39:34 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/12 13:16:26 by emajuri          ###   ########.fr       */
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
	char	*buffer;
	size_t	len;

	len = 0;
	readval = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (readval)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (-1);
		readval = read(fd, buffer, BUFFER_SIZE);
		if (readval < 0)
			return (-1);
		len += readval;
		free(buffer);
	}
	close(fd);
	if (makestr(vars, filename, len))
		return (-1);
	return (0);
}

int	makemap(t_vars *vars, char *filename)
{
	char	*dot;
	dot = ft_strrchr(filename, '.');
	if (!dot)
		return (-1);
	if (ft_strncmp(dot, ".ber", 5))
		return (-1);
	if (maptostr(vars, filename))
		return (-1);
	if (splitxy(vars->mapstr, '\n', vars))
		return (-1);
	if (validate(vars))
		return (-1);
	return (0);
}
