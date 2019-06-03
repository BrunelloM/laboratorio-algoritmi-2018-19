#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "list.h"
#include "edit_distance.h"
#include <time.h>

#define BUFFER_SIZE 256

typedef struct _WordAndDictionary {
  char *word;
  List *minimum_ed_words;
} WordAndDictionary;

int min2(int, int);

int buffer_append(char *, char);

List *get_file_words(char *);

List *get_dictionary_words(char *);

void print_string(void *);

void print_wad(void *);

WordAndDictionary *new_wad(char *);

void free_string_list(List *);

void free_wad_list(List *);

int minimum_ed(char *, List *);     // Given a string and a dictionary list, find the minimum edit distance
List *words_dic_list(List *, List *);


int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  if (argc < 3) {
    printf("Usage: edit_distance <correctme_path> <dictionary_path>\n");
    exit(EXIT_FAILURE);
  }
  clock_t start, end;
  start = clock();

  printf("\nLoading %s file...", argv[1]);
  List *correctme_words = get_file_words(argv[1]);
  printf("\nThe file has been successfully loaded into the memory.");
  printf("\nLoading %s file...", argv[2]);
  List *dictionary_words = get_dictionary_words(argv[2]);
  printf("\nThe file has been successfully loaded into the memory.");
  printf("\nCalculating minimum edit distance words...");

  Iterator *words_iterator = list_get_iterator(correctme_words);
  List *wd_list = words_dic_list(correctme_words, dictionary_words);

  list_print(wd_list, print_wad);

  iterator_dispose(words_iterator);
  free_string_list(correctme_words);
  free_string_list(dictionary_words);
  end = clock();
  printf("\nThe program took %f seconds to complete its job.", ((double) (end - start)) / CLOCKS_PER_SEC);
  return 0;
}

int buffer_append(char *string, char c) {
  int length = (int) strlen(string);

  if (length + 1 >= BUFFER_SIZE)
    return -1;

  string[length] = c;
  return 1;
}

List *get_file_words(char *filepath) {
  char c;
  char word_buffer[BUFFER_SIZE];
  List *word_list = list_create();
  FILE *fp = fopen(filepath, "r");

  if (fp == NULL) {
    printf("\nError: fopen() returned an invalid pointer value");
    exit(EXIT_FAILURE);
  }

  memset(word_buffer, 0, sizeof(word_buffer));

  while ((c = (char) fgetc(fp)) != EOF) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
      if (buffer_append(word_buffer, c) == -1) {
        printf("\nError: buffer_append() returned an error value");
        exit(EXIT_FAILURE);
      }
    } else if (c == ' ' || c == '\n') {
      list_add_tail(word_list, strdup(word_buffer));     // Create a new string and save it to the words_array
      memset(word_buffer, 0, sizeof(word_buffer));       // Empty word_buffer
    }
  }
  fclose(fp);

  return word_list;
}

List *get_dictionary_words(char *filepath) {
  assert(filepath != NULL);
  FILE *fp = fopen(filepath, "r");
  char word_buffer[BUFFER_SIZE];
  List *dic_words = list_create();

  if (fp == NULL) {
    printf("\nError: fopen() returned an invalid pointer value");
    exit(EXIT_FAILURE);
  }

  while (fgets(word_buffer, sizeof(word_buffer), fp) != NULL) {
    word_buffer[strcspn(word_buffer, "\n")] = '\0';        // Get rid of the newline character
    list_add_tail(dic_words, strdup(word_buffer));
  }

  fclose(fp);

  return dic_words;
}

void print_string(void *element) {
  printf("\n%s", ((char *) element));
}

int minimum_ed(char *string, List *dictionary) {
  assert(string != NULL && dictionary != NULL);
  unsigned int string_length = strlen(string);
  Iterator *dictionary_iterator = list_get_iterator(dictionary);
  int min_value = edit_distance_dyn(string, iterator_get_element(dictionary_iterator));

  while (iterator_is_valid(dictionary_iterator) && min_value != 0) {
    if (strlen((char *) iterator_get_element(dictionary_iterator)) == string_length) {
      min_value = min2(min_value,
                       edit_distance_dyn(string, iterator_get_element(dictionary_iterator)));
    }
    iterator_next(dictionary_iterator);
  }

  iterator_dispose(dictionary_iterator);
  return min_value;
}

int min2(int a, int b) {
  return (a < b) ? a : b;
}

List *words_dic_list(List *correctme, List *dictionary) {
  List *new_list = list_create();
  Iterator *correctme_iterator = list_get_iterator(correctme);
  Iterator *dictionary_iterator;
  char *current_word;
  int min_ed;
  WordAndDictionary *wad;

  while (iterator_is_valid(correctme_iterator)) {
    current_word = (char *) iterator_get_element(correctme_iterator);
    min_ed = minimum_ed(current_word, dictionary);
    dictionary_iterator = list_get_iterator(dictionary);
    wad = new_wad(current_word);

    while (iterator_is_valid(dictionary_iterator)) {
      if (edit_distance_dyn(current_word, iterator_get_element(dictionary_iterator)) == min_ed) {
        list_add_tail(wad->minimum_ed_words, iterator_get_element(dictionary_iterator));
      }
      iterator_next(dictionary_iterator);
    }

    list_add_tail(new_list, wad);
    iterator_dispose(dictionary_iterator);
    iterator_next(correctme_iterator);
  }
  iterator_dispose(correctme_iterator);
  return new_list;
}

WordAndDictionary *new_wad(char *string) {
  WordAndDictionary *ret_wad = (WordAndDictionary *) malloc(sizeof(WordAndDictionary));
  if (ret_wad == NULL) {
    printf("Malloc error while allocating a WordAndDictionary object!");
    exit(EXIT_FAILURE);
  }
  ret_wad->word = string;
  ret_wad->minimum_ed_words = list_create();
  return ret_wad;
}

void free_string_list(List *string_list) {
  Iterator *iterator = list_get_iterator(string_list);
  while (iterator_is_valid(iterator)) {
    free(iterator_get_element(iterator));
    iterator_next(iterator);
  }
  list_dispose(string_list);
  iterator_dispose(iterator);
}

void free_wad_list(List *wad_list) {
  Iterator *iterator = list_get_iterator(wad_list);
  while (iterator_is_valid(iterator)) {
    free_string_list(((WordAndDictionary *) iterator_get_element(iterator))->minimum_ed_words);
    iterator_next(iterator);
  }
}

void print_wad(void *element) {
  WordAndDictionary *current_el = (WordAndDictionary *) element;
  printf("\n+====================================+");
  printf("\n%s: ", current_el->word);
  list_print(current_el->minimum_ed_words, print_string);
}
