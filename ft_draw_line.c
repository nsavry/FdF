/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 11:28:39 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/25 18:52:11 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_solve_1(t_pix_plan *d, t_pix_plan *inc, t_pix_plan *p, t_env *e)
{
	int		i;
	int		cumul;

	cumul = d->y / 2;
	i = 0;
	while (i <= d->y)
	{
		p->y = p->y + inc->y;
		cumul = cumul + d->x;
		if (cumul >= d->y)
		{
			cumul = cumul - d->y;
			p->x = p->x + inc->x;
		}
		mlx_pixel_put_image(e, p->x, p->y);
		i++;
	}
}

static void	ft_solve_2(t_pix_plan *d, t_pix_plan *inc, t_pix_plan *p, t_env *e)
{
	int		i;
	int		cumul;

	i = 0;
	cumul = d->x / 2;
	i = 0;
	while (i <= d->x)
	{
		p->x = p->x + inc->x;
		cumul = cumul + d->y;
		if (cumul >= d->x)
		{
			cumul = cumul - d->x;
			p->y = p->y + inc->y;
		}
		mlx_pixel_put_image(e, p->x, p->y);
		i++;
	}
}

void		mlx_pixel_put_image(t_env *e, int x, int y)
{
	if (x < 0 || y < 0 || x > 3200 || y > 1300)
		return ;
	e->data[(9600 * y) + (3 * x)] = 255;
	e->data[(9600 * y) + (3 * x) + 1] = 255;
	e->data[(9600 * y) + (3 * x) + 2] = 255;
}

void		ft_draw_line(t_pix_plan a, t_pix_plan b, t_env *e)
{
	t_pix_plan	inc;
	t_pix_plan	d;
	t_pix_plan	p;

	p.x = a.x;
	p.y = a.y;
	d.x = b.x - a.x;
	d.y = b.y - a.y;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x = ft_abs(d.x);
	d.y = ft_abs(d.y);
	mlx_pixel_put_image(e, p.x, p.y);
	if (d.x > d.y)
		ft_solve_2(&d, &inc, &p, e);
	else
		ft_solve_1(&d, &inc, &p, e);
}
