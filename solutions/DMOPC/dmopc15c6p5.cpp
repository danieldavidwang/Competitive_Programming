#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N, K; scan(N); scan(K);
    ll a[N];

	for (int i=0; i<N; i++) {
		scan(a[i]);
	}
		
	if (N < 2 || K == 0) {
		cout << N;
		return 0;
	}
		
	deque<ll> maxq;
	deque<ll> minq; 
	
    int left = 0;
	ll ans = 0;
		
	for (int i = 0; i < N; i ++) {
	    int ai = a[i];
            
	    while (maxq.size()>0 && maxq.back()<ai) {
            maxq.pop_back();
        }
	    maxq.push_back(ai);
	        
        while(minq.size()>0 && minq.back()>ai){
            minq.pop_back();
        }
	    minq.push_back(ai);
	        
	    while (maxq.front() - minq.front() > K) {
	        ans += i-left;
	        int tmp = a[left];

	        left++;
	            
	        if(maxq.size()>0 && maxq.front() == tmp)
	            maxq.pop_front();
	        if(minq.size()>0 && minq.front() == tmp)
	            minq.pop_front();
	        }

	    }
	
	for(; left<N; left++){
	    ans += N-left;
	}
		
	cout << ans;
}