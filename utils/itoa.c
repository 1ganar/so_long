/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 06:51:14 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 09:58:18 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	count_digit(int num)
{
	int	d;

	d = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		d++;
	}
	return (d);
}

static void	convert_ita(char *num, int n)
{
	int	y;

	y = count_digit(n) - 1;
	num[y + 1] = '\0';
	while (y > -1)
	{
		num[y] = (n % 10) + 48;
		n /= 10;
		y--;
	}
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		i;

	i = 0;
	len = count_digit(n) + 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	num = (char *)malloc(sizeof(char) * len);
	if (!num)
		return (0x00);
	if (count_digit(n) < (len - 1))
	{
		num[i] = '-';
		i++;
	}
	convert_ita(&num[i], n);
	return (num);
}
