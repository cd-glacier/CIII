#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char src[100];
	fgets(src, sizeof(src), stdin);
	printf("INPUT : %s", src);

	src[strlen(src) - 1] = '\0';

	for (int i = 0; i < strlen(src); i++){
		src[i] = tolower(src[i]);
	}

	char alphabets[26] = {0, };
	for(int i = 0; i < strlen(src); i++){
		if(isalpha(src[i])) {
			alphabets[src[i] - 'a']++;
		}
	}	

	for(int i = 0; i < 26; i++){
		
	}

	for (int i = 0; i < strlen(src); i++){
		printf("%c ", src[i]);
	}

	return 0;
}



