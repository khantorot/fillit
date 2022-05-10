/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:05:46 by glychest          #+#    #+#             */
/*   Updated: 2019/11/19 19:46:12 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_pos_fig(t_fig **fig, int x, int y)
{
	int	p_x;
	int p_y;
	int i;

	i = 0;
	p_x = 21;
	p_y = 21;
	while (i < 4)
	{
		if ((*fig)->x[i] < p_x)
			p_x = (*fig)->x[i];
		if ((*fig)->y[i] < p_y)
			p_y = (*fig)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*fig)->x[i] = (*fig)->x[i] - p_x + x;
		(*fig)->y[i] = (*fig)->y[i] - p_y + y;
		i--;
	}
}

int		ft_check_pos(char **map, t_fig *fig, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (fig->y[i] < size && fig->x[i] < size &&
				map[fig->y[i]][fig->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char	**ft_alg(char **map, t_fig *fig, int size)
{
	int		x;
	int		y;
	char	**fig_map;

	if (fig->next == NULL)
		return (map);
	fig_map = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_pos_fig(&fig, x, y);
			if (ft_check_pos(map, fig, size))
				fig_map = ft_alg(ft_set_fig(map, fig, size), fig->next, size);
			if (fig_map)
				return (fig_map);
			map = ft_rm_fig(map, fig, size);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	ft_solve(t_fig *fig)
{
	char	**res;
	char	**map;
	int		size;

	size = 2;
	map = NULL;
	map = ft_new_map(map, size);
	res = NULL;
	while (!(res = ft_alg(map, fig, size)))
	{
		size++;
		ft_free_map(map);
		map = ft_new_map(map, size);
	}
	ft_show_result(res);
	while (fig)
	{
		free(fig);
		fig = fig->next;
	}
}
