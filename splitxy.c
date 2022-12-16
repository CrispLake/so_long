/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitxy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:10:03 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/15 12:22:06 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		while (s[i] == c && s[i] != 0)
		{
			i++;
			if (s[i] == 0)
				count--;
		}
		while (s[i] != c && s[i] != 0)
			i++;
		count++;
	}
	return (count);
}

static	void	ft_copystrings(char const *s, char **strings, char c)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;
	size_t	check;

	check = 1;
	i1 = 0;
	i2 = 0;
	while (s[i1] != '\0')
	{
		i3 = 0;
		while (s[i1] == c && s[i1] != '\0')
		{
			i1++;
			if (s[i1] == '\0')
				check = 0;
		}
		while (s[i1] != c && s[i1] != '\0')
			strings[i2][i3++] = s[i1++];
		if (check)
			strings[i2][i3] = '\0';
		i2++;
	}
}

static	int	ft_malloc_strings(char const *s, char c, t_vars *vars, size_t count)
{
	size_t	i1;
	size_t	i2;
	size_t	count2;

	i1 = 0;
	i2 = 0;
	while (s[i1] != c && s[i1++] != 0)
			vars->col++;
	i1 = 0;
	while (count-- > 0)
	{
		count2 = 0;
		while (s[i1] != c && s[i1++] != 0)
			count2++;
		i1++;
		if (vars->col == (int)count2)
			vars->map[i2] = malloc((count2 + 1) * sizeof(char));
		else
			vars->map[i2] = NULL;
		if (!vars->map[i2])
			return (-1);
		i2++;
	}
	return (0);
}

int	splitxy(char const *s, char c, t_vars *vars)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	vars->row = ft_word_count(s, c);
	vars->col = 0;
	vars->map = malloc(vars->row * sizeof(char *));
	if (!vars->map)
		return (-1);
	if (ft_malloc_strings(s, c, vars, vars->row))
	{
		while (vars->map[i])
			free(vars->map[i++]);
		free(vars->map);
		free(vars->mapstr);
		return (-1);
	}
	ft_copystrings(s, vars->map, c);
	return (0);
}
