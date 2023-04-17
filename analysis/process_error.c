/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:40:37 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/17 00:24:18 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	err_msg(char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str, '\0'));
	exit(1);
}

int	ft_exit(void)
{
	exit(0);
}
