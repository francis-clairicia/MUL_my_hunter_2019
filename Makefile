##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN	=	main.c

SRC		=	src/my_hunter.c				\
			src/analyse_events.c		\
			src/manage_mouse_click.c	\
			src/manage_gameplay.c		\
			src/duck.c					\
			src/duck_status.c			\
			src/duck_pos.c				\
			src/duck_list.c				\
			src/reset_duck_list.c		\
			src/duck_speed.c			\
			src/score.c					\
			src/background.c			\
			src/cursor.c				\
			src/life.c					\
			src/object/create_object.c	\
			src/object/animate_object.c	\
			src/object/resize_object.c	\
			src/object/move_object.c	\
			src/object/draw_object.c

CSFML	=	csfml/framebuffer.c			\
			csfml/create_window.c		\
			csfml/put_pixel.c			\
			csfml/draw_square.c			\
			csfml/clock.c

CFLAGS	=	-I./include/ -Wall -Wextra

OBJ	=	$(MAIN:.c=.o) $(SRC:.c=.o) $(CSFML:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib -lmy -lcsfml-system -lcsfml-graphics -lcsfml-audio
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
