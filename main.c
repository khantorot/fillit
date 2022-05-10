/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:04:54 by dtaisha           #+#    #+#             */
/*   Updated: 2019/11/19 15:33:38 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int ac, char **av)
{
	char	*line;
	t_fig	*fig;
	int		fd;

	line = NULL;
	if (ac != 2)
		return (write(1, "usage: fillit source_file\n", 26));
	else
	{
		fd = open(av[1], O_RDONLY);
		line = ft_get_next_square(fd);
		if (ft_chk_symb(&line[0], 0, 0, 0) == 0 ||
			ft_chk_neighbour(&line[0]) == 0)
		{
			if (line && *line)
				ft_strdel(&line);
			return (write(1, "error\n", 6));
		}
	}
	fig = ft_shift_fig(line);
	ft_solve(fig);
	free(line);
	return (0);
}
