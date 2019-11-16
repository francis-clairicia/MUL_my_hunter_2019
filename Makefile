##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN	=	main.c

SRC		=	src/my_hunter.c				\
			src/sprite/create_sprite.c	\
			src/sprite/animate_sprite.c	\
			src/sprite/resize_sprite.c	\
			src/sprite/move_sprite.c

CSFML	=	csfml/framebuffer.c			\
			csfml/create_window.c		\
			csfml/put_pixel.c			\
			csfml/draw_square.c			\
			csfml/analyse_events.c		\
			csfml/manage_mouse_click.c	\
			csfml/clock.c

CFLAGS	=	-I./include/ -Wall -Wextra -Werror

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o) $(CSFML:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -lcsfml-system -lcsfml-graphics
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC) tests/*.c -L./lib -lmy $(CFLAGS) --coverage -lcriterion
	./unit_tests
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) -L./lib -lmy

clean:
	rm -f $(OBJ)
	rm -f unit_tests test*.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
