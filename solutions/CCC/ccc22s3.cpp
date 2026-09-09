#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m, k; 
    scan(n); scan(m); scan(k); 
    vector<ll> v; 
    for (ll i = 0; i < n; i++) {
        ll r = n-i-1; 
        ll current = min(k-r, m);
        if (current <= 0) break;  
        ll val; 
        
        if (current > i) {
            val = min(m,i+1);
            current = val; 
        } else val = v[i-current]; 
        
        v.push_back(val);
        k -= current; 
    }

    if (k == 0 && (ll)v.size() == n) {
        for(auto x: v) {
            printf("%lld", x);
            printf(" ");
        }
    }
    else printf("-1");
}