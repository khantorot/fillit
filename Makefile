NAME = fillit
SRC = ft_chk_neighbour.c ft_chk_symb.c ft_get_next_square.c ft_map.c ft_shift.c ft_solve.c main.c
OBJ = *.o
HDR = header.h
LIB = libft/

all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc -g -Wall -Wextra -Werror -o $(NAME) $(SRC) -I $(HDR) -L. libft/libft.a

clean:
	@/bin/rm -f $(OBJ)
	make -C $(LIB) clean

fclean: clean
	@/bin/rm -f $(NAME)
	make -C $(LIB) fclean

re: fclean  all
