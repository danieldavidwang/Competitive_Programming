#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int M, N, K, maxx = 0, maxFreq = 0;
int arr[30001][1001];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int p1, p2, r, bR; cin >> p1 >> p2 >> r >> bR;
        p1--; p2--;

        for (int j = max(0, p1-r); j <= min(N-1, p1+r); j++) {
            int val = sqrt(r*r-(p1-j)*(p1-j));
            int left = max(0, p2-val);
            int right = min(M-1, p2+val);
            arr[left][j] += bR;
            arr[right+1][j] -= bR;
        }
    }
    for (int i = 0; i < M+1; i++) {
        for (int j = 0; j < N+1; j++) {
            if (i > 0) arr[i][j] += arr[i-1][j]; 
		    if (arr[i][j] == maxx) maxFreq++;
		    if (arr[i][j] > maxx) {
		        maxx = arr[i][j];
		        maxFreq = 1;
		    }
        }
    }
    cout << maxx << '\n' << maxFreq << '\n';
}