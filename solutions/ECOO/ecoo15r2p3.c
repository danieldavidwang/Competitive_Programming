#include <stdio.h>
int N;

int main() {
	for (int t = 0; t < 10; t++) {
		scanf("%d", &N);
		printf("%d\n", 2*N-1);
		scanf("%d", &N);
	}
	return 0;
}