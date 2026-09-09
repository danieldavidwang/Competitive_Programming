#include <bits/stdc++.h>
using namespace std;
long long N, a, R;

int main() {
    scanf("%lld%lld%lld", &N, &a, &R);
    printf("%lld\n", min(R/a, N));
}