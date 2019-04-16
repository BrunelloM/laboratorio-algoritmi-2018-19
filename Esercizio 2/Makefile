all: bin/main_dist

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

obj/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/main_dist: obj/edit_distance.o obj/main.o $(COMMON_DEPS)
	$(CC) -o bin/main_dist obj/edit_distance.o obj/main.o

clean:
	rm -f obj/* bin/*
