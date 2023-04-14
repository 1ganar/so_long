/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberrouk <mberrouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 05:58:15 by mberrouk          #+#    #+#             */
/*   Updated: 2023/04/12 06:42:32 by mberrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rendering_imgs(char *filename, void *mlx, void *mlx_win, t_posi obj)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	if (!img)
		err_msg("Error mlx_xpm_file_image");
	mlx_put_image_to_window(mlx, mlx_win, img, obj.c * width, obj.r * height);
	mlx_destroy_image(mlx, img);
}

void	ato_graphique(char **map, void *mlx, void *mlx_win)
{
	t_posi	obj;

	obj.r = 0;
	while (map[obj.r])
	{
		obj.c = 0;
		while (map[obj.r][obj.c])
		{
			rendering_imgs("./img/floor.xpm", mlx, mlx_win, obj);
			if (map[obj.r][obj.c] == '1')
				rendering_imgs("./img/wall.xpm", mlx, mlx_win, obj);
			else if (map[obj.r][obj.c] == 'C')
				rendering_imgs("./img/coin.xpm", mlx, mlx_win, obj);
			else if (map[obj.r][obj.c] == 'P')
				rendering_imgs("./img/player.xpm", mlx, mlx_win, obj);
			else if (map[obj.r][obj.c] == 'E')
				rendering_imgs("./img/door.xpm", mlx, mlx_win, obj);
			obj.c++;
		}
		obj.r++;
	}
}
