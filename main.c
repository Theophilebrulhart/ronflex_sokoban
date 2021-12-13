/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:50:45 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/13 13:49:46 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constantes.h"
# include "editor.h"
# include "files_management.h"
# include "game.h"
# include "mlx/mlx.h"
#include "mlx_hook.h"

int main()
{
	t_game	game;
	int	continue_play;

	continue_play = 1;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGTH, "MARIO - SOKOBAN");
	game.menu = mlx_xpm_file_to_image(game.win, "./sprites/menu.xpm", &game.width, &game.heigth);
	mlx_put_image_to_window(game.mlx, game.win, game.menu, 0, 0);
	mlx_hook(game.win, 2, 1L<<0, choose_mode, &game);
	mlx_loop(game.mlx);
	return 0;
}