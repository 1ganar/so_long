/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:42:18 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/17 00:11:09 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_parm(char *parm, int *fd)
{
	int	len;

	len = ft_strlen(parm, '\0');
	if ((len < 5) || parm[len - 1] != 'r' || parm[len - 2] != 'e'
		|| parm[len - 3] != 'b' || parm[len - 4] != '.')
		err_msg("The map file must end with the extension .ber");
	*fd = open(parm, O_RDONLY);
	if (*fd < 0)
		err_msg("An error occurred while trying to open the map file");
}

void	initial_data(t_map *data, int i)
{
	data->row_len++;
	if (!(data->col_len))
		data->col_len = i + 1;
	else if (data->col_len != (((i - (data->row_len - 1)) / data->row_len) + 1))
		err_msg("The lines not compatible !");
	if (data->col_len > 43 || data->row_len > 22)
		err_msg("The map is not compatible with resolution of screen !");
}

void	first_check(char *str, t_map *data)
{
	int	i;
	int	e;
	int	p;

	p = 0;
	i = 0;
	e = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			data->collec++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'P')
			p++;
		else if ((i == 0 && str[i] == '\n')
			|| (str[i] == '\n' && str[i + 1] == '\n')
			|| (str[i] != '\n' && str[i] != '0' && str[i] != '1'))
			err_msg("Invalid character in map !");
		if (str[i] != '\n' && (str[i + 1] == '\n' || !str[i + 1]))
			initial_data(data, i);
		i++;
	}
	if (e != 1 || p != 1 || data->collec < 1)
		err_msg("Invalid map");
}

void	second_check(t_map data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		if (i == 0 || (i == data.row_len - 1))
		{
			j = 0;
			while (data.map[i][j])
			{
				if (data.map[i][j] != '1')
					err_msg("Invalid walls !");
				j++;
			}
		}
		else
			if (data.map[i][0] != '1' || data.map[i][data.col_len - 1] != '1')
				err_msg("Invalid walls !");
		i++;
	}
}

void	main_checks(t_map *data, char *parm)
{
	int		fd;
	char	*str_map;
	char	*buf;

	str_map = NULL;
	check_parm(parm, &fd);
	buf = malloc(sizeof(char) * 11);
	if (!buf)
		err_msg("malloc fail !");
	str_map = try2read_map(str_map, buf, fd);
	if (!str_map)
		err_msg("Map problem\n");
	close(fd);
	first_check(str_map, data);
	data->map = ft_split(str_map, data);
	if (!data->map)
		err_msg("Split problem !\n");
	free(str_map);
	second_check(*data);
	get_position(data);
	check_a_solution(data, data->p.c, data->p.r);
	last_check(*data);
	recreate_a_map(data);
}
