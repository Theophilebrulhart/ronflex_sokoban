/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constantes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:26:23 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 00:04:22 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTES_H
# define CONSTANTES_H
# include <stdlib.h>
# include <stdio.h>
# define SIZE_BLOCK 34
# define NBR_BLOCK_WIDTH 12
# define NBR_BLOCK_HEIGTH 12
# define WIN_WIDTH SIZE_BLOCK * NBR_BLOCK_WIDTH
# define WIN_HEIGTH SIZE_BLOCK * NBR_BLOCK_HEIGTH

enum {UP, DOWN, LEFT, RIGHT};
enum {VOID, WALL, BOX, BOX_OK, SUPERBALL, RONFLEX};

typedef struct s_game {
	void	*menu;
	void 	*box_ok;
	void	*box;
	void 	*wall;
	void 	*superball;
	void	*ronflex_down;
	void 	*ronflex_up;
	void 	*ronflex_left;
	void 	*ronflex_right;
	void	*ronflex_orientation;
	void	*mlx;
	void	*win;
	int		heigth;
	int		width;
	int		x_position;
	int		y_position;
	int		map[NBR_BLOCK_WIDTH][NBR_BLOCK_HEIGTH];
	int		objectif;
}				t_game;

typedef struct s_position_player {
	int	x;
	int	y;
}				t_position_player;
#endif