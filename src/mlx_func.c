/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:56:25 by kychoi            #+#    #+#             */
/*   Updated: 2022/01/23 23:31:15 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	*xpm_to_img(t_game *game, char *path)
{
	int		size;
	void	*img_ptr;

	size = B_SIZE;
	img_ptr = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	if (img_ptr)
		return (img_ptr);
	printf("Error\nWrong image path:%s\n", path);
	exit(EXIT_FAILURE);
}

void	*xpm_to_img32(t_game *game, char *path)
{
	int		size32;
	void	*img_ptr;

	size32 = B_SIZE / 2;
	img_ptr = mlx_xpm_file_to_image(game->mlx, path, &size32, &size32);
	if (img_ptr)
		return (img_ptr);
	printf("Error\nWrong image path:%s\n", path);
	exit(EXIT_FAILURE);
}
