#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ソート関数
int int_comparator( const void * a , const void * b ) {
  // 引数はvoid*型と規定されているのでint型にcastする
  if( *( int * )a < *( int * )b ) {
    return 1;
  } else if( *( int * )a == *( int * )b ) {
    return 0;
  }
  return -1;
}


int main(void) {
  FILE *fp = fopen("Lesson05.txt", "r");
  if (fp == NULL) {
    puts("Can't read file.");
    return -1;
  }
  // 数値を記憶するための配列と配列の要素数
  int values[100] = {0};
  int size = 0;
  // ファイルから読み込んだ一行を記憶するための配列
  char str[100];
  while ((fgets(str, sizeof(str), fp)) != NULL) {
    // 改行コードを除去する処理
    char *p = strchr(str, (int)'\n');
    if (p != NULL) *p = '\0';
    char *token = strtok(str, ",");
    // 数値以外が来た時のエラー処理は省略
    values[size] = atoi(token);
    size++;
    while (token = strtok(NULL, ",")) {
      values[size] = atoi(token);
      size++;
    }
  }
  fclose(fp);

  // 配列をソートする
  qsort(values, size, sizeof(values[0]), int_comparator);
  // for (int i = 0; i < size; i++) printf("%d ", values[i]);

  int middle_index = size / 2;
  printf("median = %d\n", values[middle_index]);
  return 0;
}
