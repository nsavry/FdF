/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:26:39 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/27 11:40:23 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void	ft_display(t_env *e, t_pix_space co)
{
	t_pix_plan	*plan;
	int			i;

	i = 0;
	while (i < 9600 * 1300)
	{
		e->data[i] = 0;
		i++;
	}
	i = 0;
	plan = ft_turn_space_to_plan(e->map, co);
	while (e->map[i].x != 0)
		i = ft_link_pix(plan, i, e);
	free(plan);
}

static void	ft_coef_change(int x, int y, int z, t_env *e)
{
	t_pix_space	co;

	co.x = x;
	co.y = y;
	co.z = z;
	ft_display(e, co);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
}

int			expose_hook(t_env *e)
{
	int		bpp;
	int		size;
	int		endian;

	e->data = mlx_get_data_addr(e->im, &bpp, &size, &endian);
	ft_coef_change(1, 1, 1, e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 122)
		ft_coef_change(20, 28, 4, e);
	if (keycode == 120)
		ft_coef_change(8, 8, 4, e);
	if (keycode == 99)
		ft_coef_change(4, 4, 4, e);
	if (keycode == 118)
		ft_coef_change(2, 2, 2, e);
	if (keycode == 98)
		ft_coef_change(1, 1, 1, e);
	if (keycode == 65307)
		exit(0);
	return (0);
}
