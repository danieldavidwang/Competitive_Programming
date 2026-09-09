#include <bits/stdc++.h>
using namespace std;
const int MM = 210000;
int N, M, p[MM], cnt;

int find(int d) {
    if (d != p[d]) p[d] = find(p[d]);
    return p[d];
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i=1; i<=N; i++) p[i] = i;
    for (int i=1, x, y; i<=M; i++){
        scanf("%d%d", &x, &y);
        int fx = find(x), fy = find(y);
        if (fx != fy) p[fx] = fy;
        else cnt += 1;
    }
    cnt <= 1 ? (printf("YES\n")) : (printf("NO\n"));
}