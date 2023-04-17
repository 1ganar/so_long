/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:28:22 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/17 00:25:16 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_map	data;

	if (ac != 2)
		err_msg("Invalid param");
	data.col_len = 0;
	data.collec = 0;
	data.row_len = 0;
	main_checks(&data, av[1]);
	launch_game(&data);
}
