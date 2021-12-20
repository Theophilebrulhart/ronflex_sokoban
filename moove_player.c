/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:25:20 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/15 14:51:00 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"
#include "next_level.h"
#include "moove_box.h"

int	check_moove(t_game *game, int x_change, int y_change)
{
	int	valid;
	static int	save_superball = 0;
	
	if (save_superball)
	{
		game->map[game->y_position][game->x_position] = SUPERBALL;
		save_superball = 0;
	}
		
	valid = 1;
	if (game->map[game->y_position + y_change][game->x_position + x_change] == WALL 
	|| game->map[game->y_position + y_change][game->x_position + x_change] == BOX_OK)
	{
		valid = 0;
		return (valid);
	}
	if (game->map[game->y_position + y_change][game->x_position + x_change] == SUPERBALL)
		save_superball++;
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