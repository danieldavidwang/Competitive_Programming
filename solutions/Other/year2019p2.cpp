#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define m(a, b) memset(a, b, sizeof(a))
using namespace std;
const int MM = 1e6+6;
bool s[MM];
int a, b, n, m, cnts[MM], paths[MM][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m; 
    m(s, 0); m(cnts, 0);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        paths[i+1][0] = a;
        paths[i+1][1] = b;
    }

    cnts[1] = m;
    for (int i = 1; i <= n; i++) {
        if (!(cnts[i]%2)) {
            int half = cnts[i]/2;
            cnts[paths[i][0]] += half;
            cnts[paths[i][1]] += half;
        }
        else {
            int half1 = cnts[i]/2, half2 = cnts[i]-half1;
            if (!s[i]) {
                cnts[paths[i][0]] += half2;
                cnts[paths[i][1]] += half1;
            }
            else {
                cnts[paths[i][0]] += half1;
                cnts[paths[i][1]] += half2;
            }
            s[i] = !s[i];
        }
    }
    for (int i = 0; i < n; i++)
        cout << s[i+1];
    return 0;
}