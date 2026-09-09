#include <stdio.h>
int A, B, cp[1000001], ans = 0;

int isPal(int n) {
    if (n < 10) return 1;
    int rev = 0, temp = n;
    while (temp != 0) {
        rev = (rev * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (rev == n);
}

void checkPrimes() {
    cp[0] = 0;
    cp[1] = 0;
    for (int i=2; i<=1000001; i++) {
		for (int j=1; j<=1000001; j++) {
			if(i*j>1000001) break;
			cp[i*j] += 1;
		}
	}
}

int main() {
    checkPrimes();
    for (int i = 0; i < 5; i++) {
        ans = 0;
        scanf("%d%d", &A, &B);
        for (int j=A; j<B+1; j++) {
            if ((cp[j]==1) && (isPal(j)==1)) ans++;
        }
        printf("%d\n", ans);
    }
}