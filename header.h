/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:57:57 by glychest          #+#    #+#             */
/*   Updated: 2019/11/19 15:22:17 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 21

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_fig
{
	char			let;
	int				x[4];
	int				y[4];
	struct s_fig	*next;
}					t_fig;

char				*ft_get_next_square(int fd);
int					ft_chk_symb(char *l, int dt, int shrp, int row);
int					ft_chk_neighbour(char *line);
t_fig				*ft_shift_fig(char *str);
void				ft_put_fig(t_fig **tmp, char *str);
int					ft_count_fig(char *str);
void				ft_solve(t_fig *fig);
char				**ft_alg(char **map, t_fig *fig, int size);
int					ft_check_pos(char **map, t_fig *fig, int size);
void				ft_pos_fig(t_fig **fig, int x, int y);
char				**ft_new_map(char **map, int size);
char				**ft_rm_fig(char **map, t_fig *fig, int size);
char				**ft_set_fig(char **map, t_fig *fig, int size);
void				ft_show_result(char **map);
void				ft_free_map(char **map);

#endif
