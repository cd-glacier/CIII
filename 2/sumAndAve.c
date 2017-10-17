#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char str[256];
	int vals[100];

	fgets(str, 256, stdin);
	printf("Input Numbers: %s", str);

	str[strlen(str) - 1] = '\0';

	char *token = strtok(str, ", ");
	vals[0] = atoi(token);

	int index = 1;
	while(token = strtok(NULL, ", ")) {
		vals[index] = atoi(token);
		index++;
	}

	int sum = 0;	
	for(int i = 0; i < index; i++){
		sum += vals[i];
	}

	double ave = sum / index;

	printf("SUM: %d\n", sum);
	printf("AVE: %f\n", ave);
	return 0;
}



