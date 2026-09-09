#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
unsigned long long D, cnt = 0, cur[4] = {1,2,0,0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> D;
    cnt += (D/720*31);
    D %= 720;
    for (int i = 0; i < D; i++) {
        cur[3] += 1;
        if (cur[3] == 10) {
            cur[3] = 0; cur[2] += 1;
            if (cur[2] == 6) {
                cur[2] = 0; cur[1]++;
                if (cur[1] == 10) {
                    cur[1] = 0; cur[0] = 1;
                } else if (cur[1] == 3 && cur[0] == 1) {
                    cur[0] = 0; cur[1] = 1;
                }
            }
        }
        if (cur[0] == 0) {
            if (cur[3]-cur[2] == cur[2]-cur[1]) cnt++;
        }
        else if (cur[3]-cur[2] == cur[2]-cur[1] && cur[2]-cur[1] == cur[1]-cur[0]) cnt++;
    }
    cout << cnt << '\n';
}