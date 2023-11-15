##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC = $(wildcard src/*.c)\
	$(wildcard my_printf/*.c)\

OBJ = $(wildcard *~)

CFLAGS = -lcsfml-graphics -lcsfml-system\
-lcsfml-window -lcsfml-audio -lm -g3

CC = gcc

TARGET = my_radar

$(TARGET):
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS)
	make clean

all: $(TARGET)

clean:
	rm -rf $(OBJ)
	rm -rf *.html
	rm -rf html
	rm -rf *.css
	rm -rf *.gcda
	rm -rf *.gcno

fclean: clean
	rm -rf $(TARGET)
	rm -rf unitest

re: fclean all

tests_run: $(OBJ)
	$(CC) tests/test.c $(SRC) -lcriterion --coverage -o unitest
	./unitest
