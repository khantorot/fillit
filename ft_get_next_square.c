/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:09:53 by dtaisha           #+#    #+#             */
/*   Updated: 2019/11/19 19:53:45 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*ft_get_next_square(int fd)
{
	int		i;
	int		fd_fd;
	char	buff;
	char	*tmp;

	tmp = NULL;
	fd_fd = read(fd, &buff, 1);
	if (fd_fd < 0)
		return (NULL);
	i = 0;
	if (fd_fd == 1)
	{
		tmp = (char *)malloc(sizeof(char) * 545);
		while (fd_fd != '\0')
		{
			tmp[i] = buff;
			i++;
			fd_fd = read(fd, &buff, 1);
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
