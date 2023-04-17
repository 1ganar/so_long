/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:51:52 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/17 02:34:25 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	start_game(t_gpc *cnf)
{
	put_coin(cnf);
	door_case(cnf->map->e, cnf);
	mlx_key_hook(cnf->mlx_win, ky_hook, cnf);
	put_counter(cnf);
	mlx_do_sync(cnf->mlx);
	if (cnf->i >= 4)
		cnf->i = 0;
	cnf->i++;
	return (0);
}

void	put_coin(t_gpc *cnf)
{
	t_posi	obj;

	obj.r = 0;
	while (cnf->map->map[obj.r])
	{
		obj.c = 0;
		while (cnf->map->map[obj.r][obj.c])
		{
			if (cnf->map->map[obj.r][obj.c] == 'C')
				coin_anim(obj, cnf);
			obj.c++;
		}
		obj.r++;
	}
}

void	coin_anim(t_posi obj, t_gpc *cnf)
{
	rendering_imgs("./img/floor.xpm", cnf->mlx, cnf->mlx_win, obj);
	if (cnf->i == 0)
		rendering_imgs("./img/coin.xpm", cnf->mlx, cnf->mlx_win, obj);
	else if (cnf->i == 1)
		rendering_imgs("./img/coin1.xpm", cnf->mlx, cnf->mlx_win, obj);
	else if (cnf->i == 2)
		rendering_imgs("./img/coin2.xpm", cnf->mlx, cnf->mlx_win, obj);
	else if (cnf->i == 3)
		rendering_imgs("./img/coin3.xpm", cnf->mlx, cnf->mlx_win, obj);
	else if (cnf->i == 4)
		rendering_imgs("./img/coin4.xpm", cnf->mlx, cnf->mlx_win, obj);
}

void	player_mov(t_posi obj, t_gpc *cnf)
{
	rendering_imgs("./img/floor.xpm", cnf->mlx, cnf->mlx_win, obj);
	if (cnf->key == 0 || cnf->key == 123)
		rendering_imgs("./img/player_l.xpm", cnf->mlx, cnf->mlx_win, obj);
	else if (cnf->key == 2 || cnf->key == 124)
		rendering_imgs("./img/player_r.xpm", cnf->mlx, cnf->mlx_win, obj);
	else if (cnf->key == 1 || cnf->key == 125)
		rendering_imgs("./img/player_d.xpm", cnf->mlx, cnf->mlx_win, obj);
	else if (cnf->key == 13 || cnf->key == 126)
		rendering_imgs("./img/player.xpm", cnf->mlx, cnf->mlx_win, obj);
}

void	door_case(t_posi obj, t_gpc *cnf)
{
	rendering_imgs("./img/floor.xpm", cnf->mlx, cnf->mlx_win, obj);
	if (cnf->map->collec == 1)
		rendering_imgs("./img/door1.xpm", cnf->mlx, cnf->mlx_win, cnf->map->e);
	else if (cnf->map->collec == 0)
		rendering_imgs("./img/door2.xpm", cnf->mlx, cnf->mlx_win, cnf->map->e);
	else
		rendering_imgs("./img/door.xpm", cnf->mlx, cnf->mlx_win, obj);
}
