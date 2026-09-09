#pragma GCC optimize (2)

#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

long long N, mVal1 = 0, mVal2 = 0, sum = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scan(N);
    
    for (int i = 0, x; i < N; i++) {
        scan(x);
        sum += x;
        mVal1 = x;
        if (mVal1 > mVal2) mVal2 = mVal1;
    }
    long long newSum = sum/2;
    if (sum-mVal2 > newSum) cout << newSum << '\n';
    else cout << sum-mVal2 << '\n'; 
}