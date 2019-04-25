all: bin/edit_distance_main bin/dictionary_words

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

obj/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/dictionary_words: obj/edit_distance.o obj/dictionary_words.o obj/node_list.o $(COMMON_DEPS)
	$(CC) -o bin/dictionary_words obj/edit_distance.o obj/dictionary_words.o obj/node_list.o

bin/edit_distance_main: obj/edit_distance.o obj/edit_distance_main.o $(COMMON_DEPS)
	$(CC) -o bin/edit_distance_main obj/edit_distance.o obj/edit_distance_main.o

clean:
	rm -f obj/* bin/*
