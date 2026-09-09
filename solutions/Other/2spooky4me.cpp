#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define endl '\n'
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int N, L, S, a, b, s, val = 0, keyy = 0, ans;
map<int, int> spook;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scan(N); scan(L); scan(S);

    for (int i = 0; i < N; i++) {
        scan(a); scan(b); scan(s);
        spook[a] += s; spook[b+1] -= s;
    }

    for (auto &i: spook) {
        i.second = (i.second+val);
        if (val < S) ans += (i.first-keyy);
        val = i.second;
        keyy = i.first;
    }
    if (abs(spook.end()->second) < S) ans += (L-keyy);
    cout << ans << endl;
}