/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:28:51 by emajuri           #+#    #+#             */
/*   Updated: 2022/12/12 13:15:37 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1024

# include <mlx.h>
# include "libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	char	*mapstr;
	size_t	x;
	size_t	y;
	int		collectible;
	int		moves;
}	t_vars;

enum e_keys {
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

#endif
