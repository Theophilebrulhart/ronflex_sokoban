/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:57:12 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 00:26:40 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"
#include "moove_player.h"
#include "next_level.h"

void	win_game(t_game *game)
{
	static int	level = 1;

	if (level == 1)
	{
		if (!load_map(game, "./levels/level1.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
	if (level == 2)
	{
		if (!load_map(game, "./levels/level2.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
	if (level == 3)
	{
		if (!load_map(game, "./levels/level3.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
    if (level == 4)
	{
		if (!load_map(game, "./levels/level4.lvl"))
			exit(EXIT_FAILURE);
		display_game(game);
	}
    
	level++;
}