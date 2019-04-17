all: bin/edit_distance_main

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

obj/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/edit_distance_main: obj/edit_distance.o obj/edit_distance_main.o $(COMMON_DEPS)
	$(CC) -o bin/edit_distance_main obj/edit_distance.o obj/edit_distance_main.o

clean:
	rm -f obj/* bin/*
