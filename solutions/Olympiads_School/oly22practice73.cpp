#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N;
string cow, in;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> in;
    if (N > 1005) N = 1005;
    for (int i = 0; i < N; i++) cow += "moo";
    size_t found = cow.find(in);
    if (found != string::npos) cout << "yes\n";
    else cout << "no\n";
}