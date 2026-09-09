#include <stdio.h>
int T, n, sum;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n); sum = 1;
        for (int i = 2; i <= (n/i); i++) {
            if (n%i == 0) {
                sum += i;
                if (n/i != i) sum += (n/i);
            }
        }
        if (sum == n) printf("%d is a perfect number.\n", n);
        else if (sum < n) printf("%d is a deficient number.\n", n);
        else if (sum > n) printf("%d is an abundant number.\n", n);
    }
}