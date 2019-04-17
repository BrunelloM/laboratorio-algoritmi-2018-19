#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int buffer_append(char *, char);
char **get_file_words(char *);
int file_words_count(FILE *);

int main(int argc, char *argv[]) {
        if(argc < 3) {
                printf("Usage: edit_distance <correctme_path> <dictionary_path>\n");
                exit(EXIT_FAILURE);
        }

        char **words_array = get_file_words(argv[1]);

        char **iterator = words_array;
        while(*iterator != NULL) {
                printf("\n%s",*iterator);
                iterator++;
        }

	return 0;
}

int buffer_append(char *string, char c) {
        int length = (int) strlen(string);

        if(length + 1 >= BUFFER_SIZE)
                return -1;

        string[length] = c;
        return 1;
}

char **get_file_words(char *filename) {
        FILE * fp = fopen(filename, "r");
        char c;
        int index = 0;
        char word_buffer[BUFFER_SIZE];

        if(fp == NULL) {
                printf("\nError: fopen() returned an invalid pointer value");
                exit(EXIT_FAILURE);
        }

        int array_length = file_words_count(fp);

        char **words_array = (char**) malloc(sizeof(char*) * array_length);
        if(words_array == NULL) {
                printf("\nError: malloc() returned an invalid pointer value");
                exit(EXIT_FAILURE);

        }
        memset(word_buffer, 0, sizeof(word_buffer));

	while((c = (char) fgetc(fp)) != EOF)
	{
                if((c >= 65 && c <= 90 ) || (c >= 97 && c <= 122)) {
                        if(buffer_append(word_buffer, c) == -1) {
                                printf("\nError: buffer_append() returned an error value");
                                exit(EXIT_FAILURE);
                        }
                } else if(c == ' ' || c == '\n') {
                        words_array[index++] = strdup(word_buffer);     // Create a new string and save it to the words_array
                        memset(word_buffer, 0, sizeof(word_buffer));    // Empty word_buffer
                }
	}
        fclose(fp);

        return words_array;
}

int file_words_count(FILE *fp) {
        if(fp == NULL) {
                printf("\nError: invalid FILE pointer value");
                exit(EXIT_FAILURE);
        }
        int count = 0;
        char c;
        while((c = (char) fgetc(fp)) != EOF) {
                if(c == ' ' || c == '\n') {
                        count++;
                }
        }
        rewind(fp);
        return count;
}
