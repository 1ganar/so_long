/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:38:58 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 09:50:11 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	last_check(t_map data)
{
	int	x;
	int	y;

	y = 0;
	while (data.map[y])
	{
		x = 0;
		while (data.map[y][x])
		{
			if (data.map[y][x] == 'C')
				err_msg("Invalid map : you can't win the game!");
			x++;
		}
		y++;
	}
	if ((data.map[data.e.r][data.e.c - 1] != 'F'
		&& data.map[data.e.r][data.e.c - 1] != 'Y')
		&& (data.map[data.e.r][data.e.c + 1] != 'F'
		&& data.map[data.e.r][data.e.c + 1] != 'Y')
		&& (data.map[data.e.r - 1][data.e.c] != 'F'
		&& data.map[data.e.r - 1][data.e.c] != 'Y')
		&& (data.map[data.e.r + 1][data.e.c] != 'F'
		&& data.map[data.e.r + 1][data.e.c] != 'Y'))
		err_msg("Invalid map : you can't win the game!");
}

void	check_a_solution(t_map *data, int x, int y)
{
	if (x >= data->col_len || x < 0 || y >= data->row_len || y < 0
		|| data->map[y][x] == 'F' || data->map[y][x] == '1'
		|| data->map[y][x] == 'E' || data->map[y][x] == 'Y'
		|| data->map[y][x] == 'O')
		return ;
	if (data->map[y][x] == 'C')
		data->map[y][x] = 'Y';
	else
		data->map[y][x] = 'F';
	check_a_solution(data, x + 1, y);
	check_a_solution(data, x - 1, y);
	check_a_solution(data, x, y + 1);
	check_a_solution(data, x, y - 1);
}
