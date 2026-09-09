#include <bits/stdc++.h>
using namespace std;
unsigned long long a, b, c, sum, m = 42069900169420;

int main() {
    scanf("%llu%llu%llu", &a, &b, &c);
    sum = a+b+c; printf("%llu\n", sum%m);
    return 0;
}