#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char src[100];
    fgets(src, sizeof(src), stdin);
    printf("Input: %s", src);
    src[strlen(src) - 1] = '\0';
    // 入力文字列をすべて小文字に変換する。
    for (int i = 0; i < strlen(src); i++) {
        src[i] = tolower(src[i]);
    }
    // 【各文字の出現個数を昇順に表示するための方針】
    // aからzまでの文字の個数を記憶する配列を作る。
    // 文字列の文字ひとつずつに対して対応する配列の要素の値を増やしていく。
    // 配列に対して値が大きい、かつ、要素番号が小さい順に表示する。
    char alphabets[26] = {0,};
    for (int i = 0; i < strlen(src); i++) {
        if (!isalpha(src[i])) continue;
        alphabets[src[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        int max_index = 0;
        int max_count = 0;
        for (int j = 0; j < 26; j++) {
            if (alphabets[j] > max_count) {
                max_index = j;
                max_count = alphabets[j];
            }
        }
        if (max_count < 1) break;
        printf("%c(%c): %d\n", (char)max_index + 'a', toupper((char)max_index + 'a'), max_count);
        alphabets[max_index] = 0;
        max_index = 0;
        max_count = 0;
    }

    // 【単語総数出力の方針】
    // 入力文字列をstrtokの引数をスペースに指定し分割する。
    // 分割を繰り返した数をかぞえる。
    int word_count = 0;
    char *token = strtok(src, " ");
    word_count++;
    while (token = strtok(NULL, " ")) {
        word_count++;
    }
    printf("Word count: %d\n", word_count);
}


