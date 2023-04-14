/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:29:06 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 08:01:41 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "so_long.h"

typedef struct s_gpc
{
	void	*mlx;
	void	*mlx_win;
	int		key;
	int		i;
	int		stp;
	int		coin;
	t_map	*map;
}	t_gpc;

void	coin_anim(t_posi obj, t_gpc *cnf);
void	player_mov(t_posi obj, t_gpc *cnf);
void	door_case(t_posi obj, t_gpc *cnf);
int		start_game(t_gpc *cnf);
void	put_coin(t_gpc *cnf);
int		ky_hook(int key, t_gpc *data);
char	*ft_itoa(int n);
void	put_counter(t_gpc *cnf);
#endif