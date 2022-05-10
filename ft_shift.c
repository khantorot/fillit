/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:05:40 by glychest          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:48 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_count_fig(char *str)
{
	int		i;
	int		r;

	r = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			r++;
		i++;
	}
	if ((r / 4) > 26)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	return (r / 4);
}

void		ft_put_fig(t_fig **tmp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
	free(str);
}

t_fig		*ft_shift_fig(char *str)
{
	int			fig_count;
	int			add_fig;
	char		let;
	t_fig		*line;
	t_fig		*tmp;

	add_fig = -21;
	let = 'A' - 1;
	fig_count = ft_count_fig(str);
	if (!(line = (t_fig *)malloc(sizeof(t_fig))))
		return (NULL);
	tmp = line;
	while (fig_count-- > 0 && (add_fig += 21) != -1 && ++let)
	{
		tmp->let = let;
		ft_put_fig(&tmp, ft_strsub(str, add_fig, 20));
		if (!(tmp->next = (t_fig *)malloc(sizeof(t_fig))))
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (line);
}
