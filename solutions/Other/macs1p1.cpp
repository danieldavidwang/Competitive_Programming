#include <bits/stdc++.h>
using namespace std;
int H, A, S;

int main() {
    scanf("%d%d%d", &H, &A, &S);
    printf("%d\n", max((min(H, A)-S), 0));
}