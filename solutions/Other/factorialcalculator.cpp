#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, pwr; long double tmp, ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) ans += log(i);
    pwr = (int) (ans / log(10)); tmp = ans - pwr * log(10);
    printf("%.11Lfe+%d\n", exp(tmp), pwr);
    return 0;
}