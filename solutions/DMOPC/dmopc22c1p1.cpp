#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int T, N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        int arr[N+1];
        int psa[N+1];
        bool correct = true;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 0; i < N-1; i++) {
            if (arr[i] == 0 || arr[i+1] == 0) psa[i] = 0;
            else {
                int temp = arr[i]-arr[i+1];
                if (temp > 0) psa[i] = 1;
                else if (temp < 0) psa[i] = -1;
                else if (temp == 0) {
                    correct = false;
                    break;
                }
            }
        }
        if (correct) {
            int cnt = 0;
            while (psa[cnt] == 0)
                cnt++;
            while (cnt--) {
                if (psa[cnt+1] == 1) psa[cnt] = -1;
                else psa[cnt] = 1;
            }
            for (int i = 0; i < N-1; i++) {
                if (psa[i] == 0) {
                    if (psa[i-1] == 1) psa[i] = -1;
                    else psa[i] = 1;
                }
                int multVal = psa[i]*psa[i-1];
                if (multVal == 1) {
                    correct = false;
                    break;
                }
            }
        }
        if (correct) cout << "YES\n";
        else cout << "NO\n";
    }
}