#include <stdio.h>

int main(void){
	int inputNum = 0;
	scanf("%d", &inputNum);

	for(int j = 3; j <= inputNum; j++){
		int count = 0;
		if (j % 2 == 0) count++;
		for(int i = 3; i < j; i += 2) {
			if (j % i == 0) count++;
		}

		if (count == 0) {
			printf("%d ", j);
		}
	}
}


