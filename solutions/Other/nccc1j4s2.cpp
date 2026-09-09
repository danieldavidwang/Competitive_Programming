#include <bits/stdc++.h>
using namespace std;
int N, a[42];
char g[42][42];
bool r[42][42], c[42][42], determine = true;

int getV(char c) {
    if (c >= '0' && c <= '9') return (c-'0');
    return (10+c-'A');
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            int v = getV(g[i][j]);
            if (r[i][v] || c[j][v]) determine = false;
            r[i][v] = c[j][v] = true;
        }
    }
    if (!determine) { cout << "No\n"; return 0; }
    determine = true;
    for (int i=0; i<N; i++) {
        a[i] = getV(g[0][i]);
        if(i != 0 && a[i] < a[i-1]) determine = false;
    }
    for (int i = 0; i < N; i++){
        a[i] = getV(g[i][0]);
        if (i != 0 && a[i] < a[i-1]) determine = false;
    }
    determine ? (cout << "Reduced\n") : (cout << "Latin\n");
}