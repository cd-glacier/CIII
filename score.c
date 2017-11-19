#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Score {
  char id[10];
  char sex[2];
  int a;
  int b;
} Score;

int main(void) {
  FILE *fp = fopen("Lesson08_1.txt", "r");
  if (fp == NULL) {
    printf("can't create file\n"); 
    return -1; 
  }

  Score scores[15];
  int size = 0;
  char str[100];
  while(fgets(str, sizeof(str), fp) != NULL) {
    char *token = strtok(str, ",");
    strcpy(scores[size].id, token);

    token = strtok(NULL , ",");
    strcpy(scores[size].sex, token);

    token = strtok(NULL, ",");
    scores[size].a = atoi(token);

    token = strtok(NULL, ",");
    scores[size].b = atoi(token);

    size++;
  }

  double sumA = 0;
  double sumB = 0;

  for(int i = 0; i < size; i++){
    sumA += scores[i].a;
    sumB += scores[i].b;
  }

  printf("%.1f,%.1f", sumA/(double)size, sumB/(double)size);
  return 0;
}

