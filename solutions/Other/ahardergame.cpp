#include <bits/stdc++.h>
using namespace std;
int N, s1, s2, cnt, t; deque<int> a;
int main() {
    scanf("%d", &N);
    for (int i=1, x; i <= N; i++) {
        scanf("%d", &x); s1 += x; a.push_back(x);
        while ( (t=(int)a.size()) > 2 && a[t-2] >= a[t-3] && a[t-2]>=a[t-1]){
            int tmp = a[t-1] + a[t-3] - a[t-2];
            a.pop_back(); a.pop_back(); a.pop_back(); a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    for (auto u: a) {
        cnt++;
        s2 += ((cnt&1)? 1:-1)*u;
    }
    printf("%d\n", (s1+s2)/2);
}