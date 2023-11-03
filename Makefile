##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my_printf
##

SRC	=	my_printf.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_strcmp.c	\
		my_compute_power_rec.c	\
		specifier.c	\
		my_put_unsigned.c	\
		my_put_double.c	\
		my_put_gflag.c	\
		convertbase.c	\
		specifier2.c	\
		specifier3.c	\
		my_put_adresshex.c	\
		exponential.c 	\
		my_strcat.c	\
		flags.c	\
		flags2.c	\
		my_evil_str.c	\
		my_stock_nbr.c	\
		space_modifint.c	\
		space_modifstr.c	\
		space_modifbase.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

TEST_FILES	=	tests/test_my_printf.c

TEST_FCT	=	tests/test_my_function.c

CFLAGS	=	-Werror -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(NAME)
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_tests
	rm -f unit_function
	rm -f a.out
	rm -f *.o

fclean: clean

re: fclean	$(NAME)

unit_tests: fclean	$(NAME)
	gcc -o unit_tests $(NAME) $(TEST_FILES) --coverage -lcriterion -L. -lmy

unit_function: fclean	$(NAME)
	gcc -o unit_function $(NAME) $(TEST_FCT) --coverage -lcriterion -L. -lmy

test :
	gcc $(NAME) -L -lmy -Werror -Wall -Wextra

tests_run: unit_tests
	./unit_tests

tests_fct: unit_function
	./unit_function
