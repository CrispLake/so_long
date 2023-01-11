/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:28:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/01/11 15:03:55 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1024
# define F_MAX 2147483647

# include <mlx.h>
# include "libft/libft.h"
# include "stdio.h"

typedef struct s_coords
{
	int	row;
	int	col;
	int	endr;
	int	endc;
	int	f;
}	t_coords;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		**imgs;
	int			x;
	int			y;
	char		**map;
	char		*mapstr;
	int			row;
	int			col;
	int			collectible;
	int			move_count;
	t_coords	*player;
}	t_vars;

typedef struct s_cell
{
	int	closed;
	int	f;
	int	g;
	int	h;
}	t_cell;

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

enum e_chars
{
	SPACE = '0',
	WALL = '1',
	COIN = 'C',
	DOOR0 = 'E',
	DOOR1 = 'O',
	DOOR2 = '2',
	DOOR3 = '3',
	PLAYER = 'P'
};

enum e_images
{
	SPACE_IMG = 0,
	WALL_IMG = 1,
	COIN_IMG = 2,
	PLAYER_IMG = 3,
	DOOR0_IMG = 4,
	DOOR1_IMG = 5,
	DOOR2_IMG = 6,
	DOOR3_IMG = 7
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
int		free_struct(t_coords **new);
int		create_coords(t_coords *end, t_coords **coords);
int		create_images(t_vars *vars);
int		win(int move_count, t_vars *vars, int keycode);
int		destroy_all(t_vars *vars);
int		movement(int keycode, t_vars *vars);
void	display_map(t_vars *vars);
void	free_coords(void *own);
void	get_player(t_vars *vars, t_coords *player);
void	move_player(int keycode, t_vars *vars);
void	free_all(t_vars *vars, t_cell **cell_details, t_list *head, \
		t_coords *coords);
t_cell	**create_2d_cells(t_vars *vars);

#endif
