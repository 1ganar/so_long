/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:40:23 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/17 00:25:39 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_posi
{
	int	r;
	int	c;
}	t_posi;

typedef struct s_map
{
	t_posi	p;
	t_posi	e;
	char	**map;
	int		row_len;
	int		col_len;
	int		collec;
}	t_map;

typedef struct s_grpc
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}	t_grpc;

void	main_checks(t_map *data, char *parm);
void	check_parm(char *parm, int *fd);
void	second_check(t_map data);
void	initial_data(t_map *data, int i);
void	first_check(char *str, t_map *data);
void	last_check(t_map data);
void	check_a_solution(t_map *data, int x, int y);
void	err_msg(char *str);
int		ft_exit(void);
int		ft_strlen(char *str, char set);
char	*try2read_map(char *map, char *buf, int fd);
int		_str_cpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2, int len);
char	**ft_split(char *str, t_map *data);
void	get_position(t_map *data);
void	recreate_a_map(t_map *data);
void	ft_putnbr(int nbr);
void	launch_game(t_map *data);
void	rendering_imgs(char *filename, void *mlx, void *mlx_win, t_posi obj);
void	ato_graphique(char **map, void *mlx, void *mlx_win);
void	get_in_step(t_grpc *data, t_posi mov);
int		check_step(int key, t_map *data);
int		key_hook(int key, t_grpc *data);

#endif
