/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 17:27:02 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/27 20:14:51 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		ft_realloc_space(t_env *e, char **tab)
{
	int			len;

	if (e->map == NULL)
	{
		len = ft_tablen(tab);
		e->map = malloc(sizeof(t_pix_space) * (len + 1));
		e->map[len].x = 0;
		return ;
	}
	ft_space_dup(e, tab);
}

void		ft_space_dup(t_env *e, char **tab)
{
	int			i;
	int			len;
	t_pix_space *tmp;

	i = 0;
	len = ft_map_len(e);
	tmp = malloc(sizeof(t_pix_space) * (len + 1));
	while (e->map[i].x != 0)
	{
		tmp[i].x = e->map[i].x;
		tmp[i].y = e->map[i].y;
		tmp[i].z = e->map[i].z;
		i++;
	}
	tmp[i].x = 0;
	ft_return_map(tab, tmp, e);
}

void		ft_return_map(char **tab, t_pix_space *tmp, t_env *e)
{
	int		i;
	int		len;
	int		len2;

	i = 0;
	len = ft_map_len(e);
	len2 = len + ft_tablen(tab);
	e->map = malloc(sizeof(t_pix_space) * (len2 + 1));
	while (i < len2)
	{
		e->map[i].x = tmp[i].x;
		e->map[i].y = tmp[i].y;
		e->map[i].z = tmp[i].z;
		i++;
	}
	e->map[len].x = 0;
}

int			ft_tablen(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

int			ft_map_len(t_env *e)
{
	int		len;

	len = 0;
	while (e->map[len].x != 0)
		len++;
	return (len);
}
