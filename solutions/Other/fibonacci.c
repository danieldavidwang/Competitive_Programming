#include <stdio.h>

const unsigned long long qMod = 1000000007;

void multiply(unsigned long long fib[2][2], unsigned long long mat[2][2]) {
    unsigned long long a = (fib[0][0] * mat[0][0] + fib[0][1] * mat[1][0])%qMod;
    unsigned long long b = (fib[0][0] * mat[0][1] + fib[0][1] * mat[1][1])%qMod;
    unsigned long long c = (fib[1][0] * mat[0][0] + fib[1][1] * mat[1][0])%qMod;
    unsigned long long d = (fib[1][0] * mat[0][1] + fib[1][1] * mat[1][1])%qMod;
    fib[0][0] = a;
    fib[0][1] = b;
    fib[1][0] = c;
    fib[1][1] = d;
}

void power(unsigned long long fib[2][2], unsigned long long n) {
    if (n == 0 || n == 1) return;
    unsigned long long mat[2][2] = {{1,1},{1,0}};
    power(fib, n / 2);
    multiply(fib, fib);
    if (n % 2 != 0)
    multiply(fib, mat);
}

unsigned long long fibonacci_matrix(unsigned long long n) {
    unsigned long long fib[2][2] = {{1,1},{1,0}};
    if (n == 0) return 0;
    power(fib, n-1);
    return fib[0][0];
}

int main() {
   unsigned long long n; scanf("%llu", &n);
   printf("%llu", fibonacci_matrix(n));
   return 0;
}