/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_neighbour.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:12:22 by dtaisha           #+#    #+#             */
/*   Updated: 2019/11/04 21:17:39 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_chk_neighbour_in_square(char *line)
{
	int		neigh;
	int		i;

	i = 0;
	neigh = 0;
	while (i < 20)
	{
		if (line[i] == '#' && i >= 5 && line[i - 5] == '#')
			neigh++;
		if (line[i] == '#' && i >= 1 && line[i - 1] == '#')
			neigh++;
		if (line[i] == '#' && i + 5 < 20 && line[i + 5] == '#')
			neigh++;
		if (line[i] == '#' && i + 1 < 20 && line[i + 1] == '#')
			neigh++;
		i++;
	}
	return ((neigh == 6 || neigh == 8) ? 1 : 0);
}

int			ft_chk_neighbour(char *line)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if ((ft_chk_neighbour_in_square(&line[i])) == 0)
			return (0);
		i = i + 21;
	}
	return (1);
}
