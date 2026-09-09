#include <stdio.h>
using namespace std;
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        bool nas = false;
        for (int j = 1; j <= x; j++) {
            if (x%j == 0) {
                for (int k = 1; k <= x; k++) {
                    if (x%k == 0) {
                        if (x/k-k == x/j+j) { nas = true; break; }
                    }
                }
            }
        }
        if (nas) printf("%d is nasty\n", x);
        else printf("%d is not nasty\n", x);
    }
    return 0;
}