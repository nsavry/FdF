/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 14:21:26 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/27 20:10:03 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_pix_space
{
	int		x;
	int		y;
	int		z;
}				t_pix_space;

typedef struct	s_pix_plan
{
	int		x;
	int		y;
}				t_pix_plan;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*im;
	void		*imb;
	char		*data;
	t_pix_space	*map;
	int			x;
	int			y;
}				t_env;

int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
void			ft_init_space(int argc, char **argv, t_env *e);
int				ft_open_matrix(int	argc, char **argv);
void			ft_display_pix(void *mlx, void *win, t_pix_plan p, int color);
t_pix_plan		*ft_turn_space_to_plan(t_pix_space *m, t_pix_space co);
void			ft_draw_line(t_pix_plan a, t_pix_plan b, t_env *e);
int				ft_link_pix(t_pix_plan *plan, int i, t_env *e);
void			mlx_pixel_put_image(t_env *e, int x, int y);
void			ft_realloc_space(t_env *e, char **tab);
void			ft_space_dup(t_env *e, char **tab);
void			ft_return_map(char **tab, t_pix_space *tmp, t_env *e);
int				ft_tablen(char **tab);
int				ft_map_len(t_env *e);

#endif
