/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:32:40 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/27 18:01:12 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env		e;

	e.mlx = mlx_init();
	if (e.mlx == NULL)
		return (0);
	e.win = mlx_new_window(e.mlx, 2400, 1300, "Fil de Fer");
	if (e.win == NULL)
		return (0);
	e.im = mlx_new_image(e.mlx, 2400, 1300);
	e.imb = mlx_new_image(e.mlx, 2400, 1300);
	e.x = 0;
	e.y = 0;
	e.map = NULL;
	ft_init_space(argc, argv, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
