#include <bits/stdc++.h>
using namespace std;
char c[105];
int main() {
    fgets(c, sizeof c, stdin);
    for (int i = 0; c[i] != '\0'; i++) { printf("%c", c[i]); if (strchr("aeiou", c[i])!=NULL) i += 2; }
    return 0;
}