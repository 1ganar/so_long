/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:40:23 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 08:02:10 by mberrouk         ###   ########.fr       */
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

/* in analysis dir */
// in map_checks file ----------------------------------------//
void	main_checks(t_map *data, char *parm);
void	check_parm(char *parm, int *fd);
void	second_check(t_map data);
void	initial_data(t_map *data, int i);
void	first_check(char *str, t_map *data);
// in solution_checks file -----------------------------------//
void	last_check(t_map data);
void	check_a_solution(t_map *data, int x, int y);
// in process_error file -------------------------------------//
void	err_msg(char *str);
int		ft_exit(void);

/*------------------------------------------------------------*/
/*------------------------------------------------------------*/

/* in utils dir */
// in str_utils file -----------------------------------------//
int		ft_strlen(char *str, char set);
char	*try2read_map(char *map, int fd);
int		_str_cpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2, int len);
// in 2d_utils file ------------------------------------------//
char	**ft_split(char *str, t_map *data);
void	get_position(t_map *data);
void	recreate_a_map(t_map *data);
void	ft_putnbr(int nbr);

/*------------------------------------------------------------*/
/*------------------------------------------------------------*/

/* in graphics dir */
// in initial file -------------------------------------------//
void	launch_game(t_map *data);
void	rendering_imgs(char *filename, void *mlx, void *mlx_win, t_posi obj);

void	ato_graphique(char **map, void *mlx, void *mlx_win);
// in key_hook file -------------------------------------------//
void	get_in_step(t_grpc *data, t_posi mov);
int		check_step(int key, t_map *data);
int		key_hook(int key, t_grpc *data);
/*------------------------------------------------------------*/
/*------------------------------------------------------------*/

#endif
