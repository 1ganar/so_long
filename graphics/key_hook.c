/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:19:27 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/17 00:22:03 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_in_step(t_grpc *data, t_posi mov)
{
	static int	step;

	if (data->map->map[data->map->p.r][data->map->p.c] == 'C')
	{
		data->map->map[data->map->p.r][data->map->p.c] = '0';
		data->map->collec -= 1;
	}
	ft_putnbr(++step);
	write(1, "\n", 1);
	rendering_imgs("./img/floor.xpm", data->mlx, data->mlx_win, mov);
	if (data->map->map[data->map->p.r][data->map->p.c] == 'E')
		exit (0);
	data->map->map[mov.r][mov.c] = '0';
	data->map->map[data->map->p.r][data->map->p.c] = 'P';
	rendering_imgs("./img/player.xpm", data->mlx, data->mlx_win, data->map->p);
}

int	check_step(int key, t_map *data)
{
	int	c;
	int	r;

	c = 0;
	r = 0;
	if (key == 53)
		ft_exit ();
	else if (key == 0 || key == 123)
		c = -1;
	else if (key == 2 || key == 124)
		c = 1;
	else if (key == 1 || key == 125)
		r = 1;
	else if (key == 13 || key == 126)
		r = -1;
	if (data->map[data->p.r + r][data->p.c + c] == '1' || (c == 0 && r == 0)
			|| (data->map[data->p.r + r][data->p.c + c] == 'E' && data->collec))
		return (0);
	data->p.c += c;
	data->p.r += r;
	return (1);
}

int	key_hook(int key, t_grpc *data)
{
	t_posi		mov;

	mov.c = data->map->p.c;
	mov.r = data->map->p.r;
	if (!check_step(key, data->map))
		return (0);
	get_in_step(data, mov);
	return (1);
}
