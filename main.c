#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_error_message(void) {
  printf("\n");
  printf("Number must NOT contain spaces.\n");
  printf("Number must NOT contain symbols.\n");
  printf("Number must NOT be a decimal number.\n");
  printf("Number must NOT be a negative integer.\n");
  printf("Number must NOT be an even integer.\n");
  printf("Number must NOT be blank.\n");
  printf("\n");
}

char *get_substring(const char *src, int position, int length) {
  int c = 0;
  char *sub = (char *)malloc(sizeof(char) * (length + 1));

  while (c < length) {
    sub[c] = src[position + c];
    c++;
  }
  sub[c] = '\0';

  return sub;
}

int validate_user_input(const char *input, unsigned int *user_input) {
  int num_digits = 0;

  if (input[0] == '-' || input[0] == '\0') {
    print_error_message();
    return 0;
  } else {
    char *trimmed_input = get_substring(input, 0, strlen(input));

    for (int i = 0; i < strlen(trimmed_input); i++) {
      if (isdigit(trimmed_input[i])) {
        num_digits++;
      } else {
        print_error_message();
        return 0;
      }
    }

    char last_char = trimmed_input[strlen(trimmed_input) - 1];

    if ((last_char == '1') || (last_char == '3') || (last_char == '5') ||
        (last_char == '7') || (last_char == '9')) {
      *user_input = atoi(trimmed_input);
      free(trimmed_input);

      return 1;
    } else {
      free(trimmed_input);
      print_error_message();
      return 0;
    }
  }
}

unsigned int get_user_input(void) {
  while (1) {
    printf("Enter a number: ");
    unsigned int input_num = 0;

    char input[100];
    scanf("%s", input);

    int flag = validate_user_input(input, &input_num);
    if (flag) {
      return input_num;
    }
  }
}

void initial_square_array(char *square_array, unsigned int odd_int,
                          char input) {
  for (int i = 0; i < odd_int; i++) {
    for (int j = 0; j < odd_int; j++) {
      square_array[i * odd_int + j] = input;
    }
  }
}

void fill_square_array(char *square_array, unsigned int odd_int,
                       unsigned int index, char input) {
  for (int i = index; i < odd_int / 2; i += 2) {
    for (int j = i; j < odd_int - i; j++) {
      square_array[i * odd_int + j] = input;
      square_array[(odd_int - 1 - i) * odd_int + j] = input;
      square_array[j * odd_int + i] = input;
      square_array[j * odd_int + (odd_int - 1 - i)] = input;
    }
  }
}

void print_square_array(char *square_array, unsigned int odd_int) {
  for (int i = 0; i < odd_int; i++) {
    for (int j = 0; j < odd_int; j++) {
      printf("%c", square_array[i * odd_int + j]);
      printf(" ");
    }
    printf("\n");
  }
}

void print_pattern(char *square_array, unsigned int odd_int) {
  if (odd_int % 4 == 1) {
    initial_square_array(square_array, odd_int, ' ');
    fill_square_array(square_array, odd_int, 0, 'X');
  } else {
    initial_square_array(square_array, odd_int, 'X');
    fill_square_array(square_array, odd_int, 1, ' ');
  }
  print_square_array(square_array, odd_int);
}

int main(void) {
  unsigned int odd_int = get_user_input();

  char *ptr = malloc((odd_int * odd_int) * sizeof(char));
  print_pattern(ptr, odd_int);

  free(ptr);
  return 0;
}