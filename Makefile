CC=	cc

CFLAGS=	-Wall -Werror -Wextra

SRC=	push_swap.c push_functions.c r_rotate_functions.c rotate_functions.c swap_functions.c

NAME= push_swap

RM= rm -f

$(NAME): $(NAME)
	make -C ./libft all
	make -C ./ft_printf all
	$(CC) -g $(CFLAG) -o $(NAME) $(SRC) libft/libft.a ft_printf/libftprintf.a

all: $(NAME)

clean:
	$(RM) $(OBJ)
	+$(MAKE) clean -C libft
	+$(MAKE) clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	+$(MAKE) fclean -C libft
	+$(MAKE) fclean -C ft_printf

re:	fclean all
	+$(MAKE) re -C libft
	+$(MAKE) re -C ft_printf

.PHONY: all clean fclean re