#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
bool arr[MM];
int n, eul[MM];
long long ans;

void inits() {
    eul[1] = 1;
    for (int i = 2; i < MM; i++) {
        eul[i] = i-1;
        int k = floor(sqrt(i));
        for (int p = 2; p <= k; p++) {
            int j = i;
            while (!(j%p)) j /= p;
            if (i == j) continue;
            if (j == 1) eul[i] = i-(i/p);
            else eul[i] = eul[i/j]*eul[j];
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    inits();
    cin >> n;
    arr[1] = true;
    n++;
    
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        int k = floor(sqrt(t));
        vector<int> vi;
        for (int d = 1; d <= k; d++) if (!(t%d)) { vi.push_back(d); if (t != d*d) vi.push_back(t/d); }
        for (auto itr = vi.begin(); itr != vi.end(); itr++) if (!arr[*itr]) { arr[*itr] = true; ans += eul[*itr]; }
    }
    cout << ans << '\n';
    return 0;
}