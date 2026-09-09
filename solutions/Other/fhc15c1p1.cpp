#pragma GCC optimize ("Ofast, unroll-loops")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

int *checkPrimes(int x) {
    int *cp = new int[x+1];
    
    cp[0] = 0;
    cp[1] = 0;

    for (int i=2; i<=x; i++) {
		if(cp[i] >= 1) continue;
		if(cp[i] == 0) {
			for (int j=1; j<=x; j++) {
				if(i*j>x) break;
				cp[i*j] += 1;
			}
		}
	}
    return cp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;

    for (int i=0; i<T; i++) {
		int A, B, K; cin >> A >> B >> K;
		int ans=0;
		
		int *arr = checkPrimes(B);
		
        for (int j=A; j<B+1; j++) {
			if (arr[j] == K) ans++;
		}	
		cout << "Case #" << (i+1) << ": " << ans << '\n';	
	}	
}