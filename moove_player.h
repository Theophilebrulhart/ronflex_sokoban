/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:28:49 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/13 21:00:33 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOOVE_PLAYER_H
# define MOOVE_PLAYER_H

void	    box_stuck(t_game *game, int x_change, int y_change);
void	moove_player(int keycode, t_game *game);
int	    check_moove(t_game *game, int x_change, int y_change);
int	    box_moove(t_game *game, int x_change, int y_change);
#endif