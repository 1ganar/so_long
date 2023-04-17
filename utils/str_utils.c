/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:47:36 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/17 00:04:08 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str, char set)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != set)
		len++;
	return (len);
}

int	_str_cpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

char	*try2read_map(char *map, char *buf, int fd)
{
	int		readbit;
	int		len;

	readbit = 1;
	len = 0;
	while (readbit)
	{
		readbit = read(fd, buf, 10);
		if (readbit < 0)
		{
			if (map)
				free(map);
			free(buf);
			return (NULL);
		}
		buf[readbit] = '\0';
		len += readbit;
		if (readbit)
			map = ft_strjoin(map, buf, len);
	}
	free(buf);
	return (map);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	int		i;
	int		j;
	char	*resl;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	resl = malloc((sizeof(char) * (len + 1)));
	while (s1 && s1[i])
	{
		resl[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		resl[i + j] = s2[j];
		j++;
	}
	resl[i + j] = '\0';
	if (s1)
		free(s1);
	return (resl);
}
