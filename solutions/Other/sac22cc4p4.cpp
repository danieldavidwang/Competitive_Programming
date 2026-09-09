#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int> 
using namespace std;
const int MM = 1e6+6;
int N, B, T, a[MM];

ll func(int x) {
    priority_queue<pii> mx;
    priority_queue<pii, vector<pii>, greater<pii>> mi;
    ll counter = 0;
    
    for (int left = 1, right = 1; right <=N; right++) {
        while (!mx.empty() && mx.top().second < left) mx.pop();
        while (!mi.empty() && mi.top().second < left) mi.pop();
        mx.push({a[right], right});  mi.push({a[right], right});
        while(!mx.empty() && !mi.empty() && mx.top().first - mi.top().first > x){
            while (mx.top().second <= left && !mx.empty()) mx.pop();
            while (mi.top().second <= left && !mi.empty()) mi.pop();
            left++;
        }
        counter += (-left+right+1);
    }
    return counter;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B >> T;
    for (int i = 1; i <= N; i++) cin >> a[i];
    cout << func(T)-func(B-1) << '\n';
}