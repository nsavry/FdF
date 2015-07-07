/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:32:40 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/27 20:14:52 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_space(int argc, char **argv, t_env *e)
{
	int			fd;
	t_pix_plan	p;
	char		**tab;
	char		*line;

	p.x = 0;
	fd = ft_open_matrix(argc, argv);
	while (ft_get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		ft_realloc_space(e, tab);
		p.y = 0;
		while (tab[p.y] != NULL)
		{
			e->map[e->x].x = p.x + 1;
			e->map[e->x].y = p.y + 1;
			e->map[(e->x)++].z = ft_atoi(tab[p.y++]);
		}
		e->y = p.y;
		p.x++;
	}
	e->map[e->x].x = 0;
}

int			ft_open_matrix(int argc, char **argv)
{
	int		fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("map/test_42_1.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Error: File not found");
		exit(0);
	}
	return (fd);
}

void		ft_display_pix(void *mlx, void *win, t_pix_plan p, int color)
{
	if (mlx == NULL || win == NULL)
		exit(0);
	mlx_pixel_put(mlx, win, p.x, p.y, color);
}

t_pix_plan	*ft_turn_space_to_plan(t_pix_space *m, t_pix_space co)
{
	t_pix_plan	*p;
	t_pix_space	t;
	t_pix_space	var;

	t.z = 0;
	var.x = 0;
	var.y = 0;
	while (m[var.x].x == 1)
		var.x++;
	while (var.x != 0 && m[t.z].x != 0)
	{
		if (t.z++ % var.x == 0)
			var.y++;
	}
	var.z = ((var.y / 2) * var.x) + (var.x / 2);
	t.x = 1600 - (-40 / co.x * m[var.z].x) - (28 / co.y * m[var.z].y);
	t.y = 650 - (28 / co.y * m[var.z].y);
	p = (t_pix_plan *)malloc(sizeof(t_pix_plan) * (t.z + 1));
	t.z = -1;
	while (m[++t.z].x != 0)
	{
		p[t.z].x = t.x + (-40 / co.x * m[t.z].x) + (28 / co.y * m[t.z].y);
		p[t.z].y = t.y + (28 / co.y * m[t.z].y) + (-4 / co.z * m[t.z].z);
	}
	return (p);
}

int			ft_link_pix(t_pix_plan *plan, int i, t_env *e)
{
	if (e->y != 0 && ((i + 1) % e->y) != 0 && i < (e->x - e->y))
	{
		ft_draw_line(plan[i], plan[i + 1], e);
		ft_draw_line(plan[i + e->y], plan[i], e);
	}
	if (e->y != 0 && ((i + 1) % e->y) == 0 && i < (e->x - e->y))
		ft_draw_line(plan[i + e->y], plan[i], e);
	if (e->y != 0 && ((i + 1) % e->y) != 0 && i >= (e->x - e->y))
		ft_draw_line(plan[i], plan[i + 1], e);
	i++;
	return (i);
}
