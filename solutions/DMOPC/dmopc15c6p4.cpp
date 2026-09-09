#include <bits/stdc++.h>
using namespace std;
vector<int> disj(100001, -1);
struct E { int u, v, w; };
vector<E> values;
int counter = 0, n, k, in;

bool cmp(E a, E b) { return a.w<b.w; }

int fd (int a) {
    if (disj[a] == a) return a;
    else return disj[a] = fd(disj[a]);
}

void uni (int a, int b) {
    int fa = fd(a), fb = fd(b);
    if (fa != fb) disj[fb] = fa;
}

int main(){
    cin >> n >> k;
    for (int x = 0; x < n; x++) disj[x] = x;
    for (int x = 0; x < n-k; x++) uni(x, x+k);
    for (int x = 0; x < n-1; x++) { cin >> in; values.push_back(E{x, x+1, in}); }
    sort(values.begin(), values.end(), cmp);
    for (int x = 0, cnt = 0; x < values.size(); x++) {
        int fu = fd(values[x].u), fv = fd(values[x].v);
        if (fu != fv){
            uni(fu, fv); cnt++;
            counter += values[x].w;
            if(cnt == k-1) break;
        }
    }
    cout << counter << '\n';
}