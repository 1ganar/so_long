/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:56:17 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 06:42:11 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	launch_game(t_map *data)
{
	t_grpc	conf;
	int		width;
	int		height;

	width = data->col_len * 60;
	height = data->row_len * 60;
	conf.map = data;
	conf.mlx = mlx_init();
	conf.mlx_win = mlx_new_window(conf.mlx, width, height, "SO_LONG");
	ato_graphique(data->map, conf.mlx, conf.mlx_win);
	mlx_key_hook(conf.mlx_win, key_hook, &conf);
	mlx_hook(conf.mlx_win, 17, 0L, ft_exit, 0x00);
	mlx_loop(conf.mlx);
}
