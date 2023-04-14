/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:32:58 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 10:23:20 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_counter(t_gpc *cnf)
{
	t_posi	cntr;

	cntr.c = 0;
	cntr.r = 0;
	rendering_imgs("./img/cntr.xpm", cnf->mlx, cnf->mlx_win, cntr);
	mlx_string_put(cnf->mlx, cnf->mlx_win, 15, 20, 0, ft_itoa(cnf->stp));
}

void	get_step(t_gpc *data, t_posi mov)
{
	void		*mlx;
	void		*mlx_win;

	mlx = data->mlx;
	mlx_win = data->mlx_win;
	if (data->map->map[data->map->p.r][data->map->p.c] == 'C')
	{
		data->map->map[data->map->p.r][data->map->p.c] = '0';
		data->map->collec -= 1;
	}
	rendering_imgs("./img/floor.xpm", mlx, mlx_win, mov);
	ft_putnbr(++data->stp);
	write(1, "\n", 1);
	player_mov(data->map->p, data);
	if (data->map->map[data->map->p.r][data->map->p.c] == 'E')
		exit (0);
	data->map->map[mov.r][mov.c] = '0';
	data->map->map[data->map->p.r][data->map->p.c] = 'P';
}

int	ky_hook(int key, t_gpc *data)
{
	t_posi		mov;

	mov.c = data->map->p.c;
	mov.r = data->map->p.r;
	if (key == 0 || key == 123 || key == 2 || key == 124
		|| key == 1 || key == 125 || key == 13 || key == 126)
		data->key = key;
	if (!check_step(key, data->map))
		return (0);
	get_step(data, mov);
	return (1);
}

void	launch_game(t_map *data)
{
	t_gpc	conf;
	int		width;
	int		height;

	width = data->col_len * 60;
	height = data->row_len * 60;
	conf.key = 0;
	conf.coin = data->collec;
	conf.i = 0;
	conf.stp = 0;
	conf.map = data;
	conf.mlx = mlx_init();
	conf.mlx_win = mlx_new_window(conf.mlx, width, height, "SO_LONG");
	ato_graphique(data->map, conf.mlx, conf.mlx_win);
	mlx_hook(conf.mlx_win, 17, 0L, ft_exit, NULL);
	mlx_loop_hook(conf.mlx, start_game, &conf);
	mlx_loop(conf.mlx);
}
