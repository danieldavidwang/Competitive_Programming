#include <stdio.h>
int A, B, cp[1000001];

void checkPrimes(int x) {
    cp[0] = 0; cp[1] = 0;
    for (int i=2; i<=x; i++) {
		if(cp[i] >= 1) continue;
		if(cp[i] == 0) {
			for (int j=1; j<=x; j++) {
				if(i*j>x) break;
				cp[i*j] += 1;
			}
		}
	}
}

int main() {
    scanf("%d%d", &A, &B);
	checkPrimes(B);
    for (int j=A; j<B+1; j++)
        printf("%d\n", cp[j]);
}