/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk_symb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtaisha <dtaisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:11:06 by dtaisha           #+#    #+#             */
/*   Updated: 2019/11/04 21:15:55 by dtaisha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_chk_symb(char *l, int dt, int shrp, int row)
{
	while (l)
	{
		dt = 0;
		shrp = 0;
		row = 0;
		while (dt <= 12 && shrp <= 4 && row < 4 && (*l == '.' ||
		*l == '#' || *l == '\n' || *l == '\0'))
		{
			if (*l == '.')
				dt++;
			else if (*l == '#')
				shrp++;
			else if (*l == '\n' || *l == '\0')
				row++;
			if (*l == '\0')
				break ;
			l++;
		}
		if (dt == 12 && shrp == 4 && row == 4 && *l == '\n')
			l++;
		else
			break ;
	}
	return ((dt == 12 && shrp == 4 && row == 4 && *l == '\0') ? 1 : 0);
}
