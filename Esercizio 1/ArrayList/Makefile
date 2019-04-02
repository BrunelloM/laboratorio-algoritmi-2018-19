all: bin/list_array bin/list_array_tests

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

obj/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/list_array: obj/list.o obj/main.o $(COMMON_DEPS)
	$(CC) -o bin/list_array obj/list.o obj/main.o

bin/list_array_tests: obj/list_tests.o obj/list.o obj/unity.o $(COMMON_DEPS)
	$(CC) -o bin/list_array_tests  obj/list_tests.o obj/list.o obj/unity.o

clean:
	rm -f obj/* bin/*
