#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Word {
  char content[20];
} Word;

int main(void) {
  FILE *fp = fopen("Lesson08_2.txt", "r");
  if (fp == NULL) {
    printf("can't create file\n");
    return -1;
  }

  Word words[200];
  int size = 0;
  char str[1000];
  while(fgets(str, sizeof(str), fp) != NULL) {
    char *token = strtok(str, ",/ /.");
    strcpy(words[size].content, token);
    size++;

    while(token = strtok(NULL, ",/ /.")) {
      if (strcmp(token, " ")) {
        strcpy(words[size].content, token);
        size++;
      }
    }

    // 改行後の空白を消すため
    size--;
  }

  int sum = 0;
  for (int i = 0; i < size; i++){
    sum += strlen(words[i].content);
  }

  printf("words num  : %d\n", size);
  printf("symbols num: %d\n", sum);

  return 0;
}


