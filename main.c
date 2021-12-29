/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:34:41 by kyubongchoi       #+#    #+#             */
/*   Updated: 2021/12/29 20:40:27 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <OpenGL/gl.h>
#include "mlx.h"
// #include "mlx_int.h"
// #include "mlx_new_window.h"
// #include "mlx_opengl.h"
// #include "mlx_png.h"

int	main(int ac, char **av)
{
	int		fd;
	void	*mlx;
	void	*win;

	(void)ac;
	(void)av;

	// fd = open(av[1], O_RDONLY);
	// close(fd);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "hello");
	while(1)
	mlx_pixel_put(mlx, win, 50, 50, 0x00111111);
	printf("mlx[%p] win[%p]\n", mlx, win);
	return (0);
}
// char	*str;
// while ((str = get_next_line(fd)) != NULL)
// 	printf("%s", str);