CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
LDFLAGS = -lSDL2 -lm
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)

SRC = src/main.c src/raycaster.c src/map.c
OBJ = $(SRC:.c=.o)
EXEC = maze_game

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(SDL_LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(SDL_CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
