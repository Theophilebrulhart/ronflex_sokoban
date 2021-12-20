/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_box.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:05:34 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 15:09:05 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOOVE_BOX_H
# define MOOVE_BOX_H

int	box_stuck(t_game *game, int x_change, int y_change);
int	box_moove(t_game *game, int x_change, int y_change);
#endif