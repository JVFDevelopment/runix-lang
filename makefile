CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = main.o game_loop.o graphics.o input.o physics.o audio.o assets.o game_objects.o
DEPS = game_loop.h graphics.h input.h physics.h audio.h assets.h game_objects.h

%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runix: $(OBJ)
	$(CC) -o runix $(OBJ)

clean:
	rm -f *.o runix
