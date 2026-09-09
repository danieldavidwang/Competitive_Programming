#pragma GCC optimize (2)

#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int M, minVal, maxVal, cnt = 0, l = -1;
const int MM = 1e6+1e5+2;
int arr[MM];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    scan(M); scan(arr[0]); scan(arr[1]); scan(arr[2]);
    
    for (int i = 3; i < M; i++) {
        scan(arr[i]);
        
        if (arr[i-1] > arr[i]) continue;
        minVal = arr[i]; maxVal = arr[i];
        int temp = 0;
        
        for (int j = i-1; j >= 0; j--) {
            temp = arr[j]-arr[i];
			if (j<=l) break;
			if ((i-j) == M-1) break;
			if (minVal>arr[j]) minVal = arr[j];
			if (maxVal<arr[j]) maxVal = arr[j];
			if ((minVal!=arr[j]) || (maxVal!=arr[i])) continue;
			if ((temp <= -3) && (temp==(j-i))) {
			    cnt++;
			    ans.push_back(j+1); ans.push_back(i+1);
			    l = j;
			    break;
			}
        }
    }
    
    if (!cnt) {
        cout << "1\n1 " << M;
    } else {
        cout << cnt << '\n';
        for (auto itr = ans.begin(); itr != ans.end();) {
            cout << *itr << " ";
            itr++;
            cout << *itr << '\n';
            itr++;
        }
    }
}