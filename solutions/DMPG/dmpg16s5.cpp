#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

const int MM = 1e5+5;
typedef long long ll;
int N, K; ll psa[2*MM+1], ans; deque<int> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> psa[i]; psa[i+N] = psa[i];
    }
    v.push_back(0);
    
    for(int j = 1; j <= 2*N; j++) {
        psa[j] += psa[j-1];
        if (!v.empty() && v.front() < j-K) v.pop_front();
        while (!v.empty() && psa[v.back()] >= psa[j]) v.pop_back();
        v.push_back(j);
        ans = max(ans, psa[j] - psa[v.front()]);
    }
    cout << ans << '\n';
}