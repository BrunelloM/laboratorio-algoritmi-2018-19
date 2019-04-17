#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct _WordsContainer {
        char **array;
        int size;
} WordsContainer;

int buffer_append(char *, char);
void dispose_words_container(WordsContainer *);
WordsContainer *get_file_words(char *);
int file_words_count(FILE *);
void print_minimum_ed_words(char);

int main(int argc, char *argv[]) {
        if(argc < 3) {
                printf("Usage: edit_distance <correctme_path> <dictionary_path>\n");
                exit(EXIT_FAILURE);
        }

        WordsContainer *words_container = get_file_words(argv[1]);

        for(int i = 0; i < words_container->size; i++) {
                printf("\n%s", words_container->array[i]);
        }

        dispose_words_container(words_container);

	return 0;
}

int buffer_append(char *string, char c) {
        int length = (int) strlen(string);

        if(length + 1 >= BUFFER_SIZE)
                return -1;

        string[length] = c;
        return 1;
}

WordsContainer *get_file_words(char *filename) {
        FILE * fp = fopen(filename, "r");
        char c;
        int index = 0;
        WordsContainer* words_container = (WordsContainer*) malloc(sizeof(words_container));

        if(words_container == NULL) {
                printf("\nError: malloc() returned an invalid pointer value");
                exit(EXIT_FAILURE);
        }

        char word_buffer[BUFFER_SIZE];

        if(fp == NULL) {
                printf("\nError: fopen() returned an invalid pointer value");
                exit(EXIT_FAILURE);
        }

        words_container->size = file_words_count(fp);
        words_container->array = (char**) malloc(sizeof(char*) * (unsigned long int) words_container->size);

        if(words_container->array == NULL) {
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
                        words_container->array[index++] = strdup(word_buffer);     // Create a new string and save it to the words_array
                        memset(word_buffer, 0, sizeof(word_buffer));    // Empty word_buffer
                }
	}
        fclose(fp);

        return words_container;
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

void dispose_words_container(WordsContainer *words_container) {
        for(int i = 0; i < words_container->size; i++)
                free(words_container->array[i]);
        free(words_container);
}

void print_minimum_ed_words(char *dictionary_fname) {

}
