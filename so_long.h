/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:28:51 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/16 17:06:38 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1024
# define F_MAX 2147483647

# include <mlx.h>
# include "libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*mapstr;
	int		row;
	int		col;
	int		collectible;
	int		moves;
}	t_vars;

typedef struct s_cell
{
	int	closed;
	int	parent_row;
	int	parent_col;
	int	f;
	int	g;
	int	h;
}	t_cell;

typedef struct s_coords
{
	int	row;
	int	col;
	int	f;
	int	g;
	int	h;
}	t_coords;

enum e_keys
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	UP = 126,
	LEFT = 123,
	DOWN = 125,
	RIGHT = 124
};

int	makemap(t_vars *vars, char *filename);
int	splitxy(char const *s, char c, t_vars *vars);
int	validate(t_vars *vars);
int	check_path(t_vars *vars);

#endif
