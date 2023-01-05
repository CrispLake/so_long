/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:28:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/05 17:20:22 by emajuri          ###   ########.fr       */
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
	void	*img;
	int		x;
	int		y;
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
	int	f;
	int	g;
	int	h;
}	t_cell;

typedef struct s_coords
{
	int	row;
	int	col;
	int	endr;
	int	endc;
	int	f;
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

int		makemap(t_vars *vars, char *filename);
int		splitxy(char const *s, char c, t_vars *vars);
int		validate(t_vars *vars);
int		check_path(t_vars *vars);
int		successor_north(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details);
int		successor_south(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details);
int		successor_west(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details);
int		successor_east(t_vars *vars, t_coords *coords, t_list **head, \
		t_cell **cell_details);
int		add_node(t_list **head, int f, int row, int col);
int		is_valid(t_vars *vars, int row, int col);
int		create_open_list(t_list **head, int f, t_coords *own);
int		create_open_list(t_list **head, int f, t_coords *own);
int		add_node(t_list **head, int f, int row, int col);
int		free_struct(t_coords **new);
int		create_coords(t_coords *end, t_coords **coords);
void	free_all(t_vars *vars, t_cell **cell_details, t_list *head, \
		t_coords *coords);
t_cell	**create_2d_cells(t_vars *vars);
void	free_coords(void *own);

#endif
