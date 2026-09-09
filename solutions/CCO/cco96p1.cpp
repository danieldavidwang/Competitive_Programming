#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e2;
int N, T, ans, a[MM];

int fun() {
    ans = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) scanf("%d", &a[i]);

    for (int i = 1; i < T; i++)
        for (int j = 0; j < i; j++)
            if (a[i] < a[j]) ans++;
    return ans;
}

int main() {
    scanf("%d", &N);
    while (N--) { printf("Optimal train swapping takes %i swaps.\n", fun()); }
    return 0;
}