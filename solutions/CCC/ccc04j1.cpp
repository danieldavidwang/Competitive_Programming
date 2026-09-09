#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cout << "The largest square has side length " << floor(sqrt(N)) << ".\n";
}