NAME = libftprintf.a
SRC = ft_printf.c addcharn.c big_hex.c c.c di.c f.c hex.c integer.c o.c octal.c oktotorp.c parse.c s.c x.c b.c binary.c di.c f.c f_round.c fraction.c fraction_path.c ft_vector.c func.c math_op_with_the_five.c multy_two.c nan.c percent.c print_f.c u.c uinteger.c whole.c select_round.c uflags.c oflags.c xflags.c x_check_flags.c di_ifelse_precison.c octal_chck_flags.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a libftprintf.a
	gcc -Wall -Wextra -Werror -c $(SRC) -I. -Ilibft
	ar -r $@ $(OBJ)
	ranlib $@
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
clean:
	make -C libft clean
	rm -f $(OBJ)
re: fclean all
