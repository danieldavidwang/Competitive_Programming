#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int t, n, cst;

void solve() {
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    cst = 0;
    
    for (int i = 0; i < n-1; i++) {
        int gud = i;
        for (int j = i+1; j < n; j++) if (A[j] < A[gud]) gud = j;
        cst += gud - i+1;
        for (int j = i; j < i+(gud+1-i)/2; j++) swap(A[gud-j+i], A[j]);
    }
    cout << cst << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int a = 1; a < (t+1); a++) { cout << "Case #" << a << ": "; solve(); }
    return 0;
}