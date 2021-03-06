/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:31:26 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/14 18:05:59 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HOOK_H
# define MLX_HOOK_H

int	choose_mode(int keycode, t_game *game);
int change_position(int keycode, t_game *game);
int	map_change(int keycode, t_game *game);
#endif