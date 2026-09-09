#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N; cin >> N;
    int arr[N];
    int arr2[N];
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    
    for (int j = 0; j < N; j++) {
        if (arr2[j] == arr[N-2]) {
            cout << j+1;
            return 0;
        }
    }
}