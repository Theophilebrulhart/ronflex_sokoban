/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:25:20 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 00:22:35 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"
#include "next_level.h"

int	box_stuck(t_game *game, int x_change, int y_change)
{
	(void)y_change;
	
	if (x_change)
	{
		printf("VALEUR DE X_CHANGE : %d\n", x_change);
		if (game->map[game->y_position - x_change][game->x_position + x_change] == WALL || game->map[game->y_position + x_change][game->x_position + x_change] == WALL)
		{
			if (x_change > 0)
			{
				if (game->map[game->y_position + 1][game->x_position + 1] != WALL)
					game->map[game->y_position + 1][game->x_position + 1] = BOX;
				if (game->map[game->y_position - 1][game->x_position + 1] != WALL)
					game->map[game->y_position - 1][game->x_position + 1] = BOX;
			}
			if (x_change < 0)
			{
				if (game->map[game->y_position + 1][game->x_position - 1] != WALL)
					game->map[game->y_position + 1][game->x_position - 1] = BOX;		
				if (game->map[game->y_position - 1][game->x_position - 1] != WALL)
					game->map[game->y_position - 1][game->x_position - 1] = BOX;			
			}
			return (1);
		}
			
	}
	if (y_change)
	{
		if (game->map[game->y_position + y_change][game->x_position + y_change] == WALL || game->map[game->y_position + y_change][game->x_position - y_change] == WALL)
		{
			printf("DEBLOQUE SUR LE COTE GAUCHE\n");
			if (y_change > 0)
			{
				if (game->map[game->y_position + 1][game->x_position - 1] != WALL)
					game->map[game->y_position + 1][game->x_position - 1] = BOX;
				if (game->map[game->y_position + 1][game->x_position + 1] != WALL)
					game->map[game->y_position + 1][game->x_position +1] = BOX;
			}
			if (y_change < 0)
			{
				if (game->map[game->y_position - 1][game->x_position - 1] != WALL)
					game->map[game->y_position - 1][game->x_position - 1] = BOX;
				if (game->map[game->y_position - 1][game->x_position + 1] != WALL)
					game->map[game->y_position - 1][game->x_position +1] = BOX;
			}
			return (1);
		}
			
	}
	return (0);
}

int	box_moove(t_game *game, int x_change, int y_change)
{
	int	valid;

	valid = 1;
		if (game->map[game->y_position + y_change][game->x_position + x_change] == BOX)
		{
			if (game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == WALL)
			{
				if (box_stuck(game, x_change, y_change))
				{
					printf("VA FALLOIR DEBLOQUER LA CAISSE\n");
					return (valid);
				}
				valid = 0;
				return (valid);
			}
			if (game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == SUPERBALL)
			{
				game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] = BOX_OK;
				game->objectif += -1;
				printf("NOMBRE D'OBJECTIF\n : %d\n", game->objectif);
				if (game->objectif == 0)
				{
					game->ronflex_orientation = game->ronflex_down;
					win_game(game);
					return (0);
				}
					
				return (valid);
			}
			game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] = BOX;
		}
	return (valid);
}

int	check_moove(t_game *game, int x_change, int y_change)
{
	int	valid;
	
	valid = 1;
	if ((game->map[game->y_position + y_change][game->x_position + x_change] == BOX && game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX) 
	|| (game->map[game->y_position + y_change][game->x_position + x_change] == BOX && game->map[game->y_position + (y_change * 2)][game->x_position + (x_change * 2)] == BOX_OK) 
	|| game->map[game->y_position + y_change][game->x_position + x_change] == WALL 
	|| game->map[game->y_position + y_change][game->x_position + x_change] == BOX_OK)
	{
		valid = 0;
		return (valid);
	}
	valid = box_moove(game, x_change, y_change);
	return (valid);
}

void	moove_player(int keycode, t_game *game)
{
	if (keycode == 0 && check_moove(game, -1 , 0))
	{
		game->x_position += -1;
		game->map[game->y_position][game->x_position] = RONFLEX;
		display_game(game);
	}
	if (keycode == 1  && check_moove(game, 0, +1))
	{
		game->y_position += 1;
		game->map[game->y_position][game->x_position] = RONFLEX;
		display_game(game);
	}
	if (keycode == 2  && check_moove(game, +1, 0))
	{
		game->x_position += 1;
		game->map[game->y_position][game->x_position] = RONFLEX;
		display_game(game);
	}
	if (keycode == 13  && check_moove(game, 0, -1))
	{
		game->y_position += -1;
		game->map[game->y_position][game->x_position] = RONFLEX;
		display_game(game);
	}
}