

all: bin/list

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/list: build/list.o build/main.o $(COMMON_DEPS)
	$(CC) -o bin/list build/list.o build/main.o

clean:
	rm -f build/* bin/*
