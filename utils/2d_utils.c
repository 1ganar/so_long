/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:45:45 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 09:52:53 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

char	**ft_split(char *str, t_map *data)
{
	char	**resl;
	int		i;
	int		j;

	j = 0;
	i = 0;
	resl = malloc(sizeof(char *) * (data->row_len + 1));
	if (!resl)
		err_msg("malloc failed !");
	resl[data->row_len] = NULL;
	while (str[i])
	{
		resl[j] = malloc(sizeof(char) * (data->col_len + 1));
		if (!resl[j])
			err_msg("malloc failed !");
		i += _str_cpy(resl[j], &str[i]);
		if (!str[i])
			break ;
		j++;
		i++;
	}
	return (resl);
}

void	get_position(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
			{
				data->e.c = x;
				data->e.r = y;
			}
			else if (data->map[y][x] == 'P')
			{
				data->p.c = x;
				data->p.r = y;
			}
			x++;
		}
		y++;
	}
}

void	recreate_a_map(t_map *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'F')
				data->map[y][x] = '0';
			else if (data->map[y][x] == 'Y')
				data->map[y][x] = 'C';
			x++;
		}
		y++;
	}
	data->map[data->e.r][data->e.c] = 'E';
	data->map[data->p.r][data->p.c] = 'P';
}
