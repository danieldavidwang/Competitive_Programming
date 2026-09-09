#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int SIZE = 27;
map<char, vector<char>> cyc;
map<char, char> e;
vector<char> chars {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_' };
string l, ans = "";
char c;
int N, j;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 0; i < SIZE; i++) { cin >> c; e[chars[i]] = c; }
    for (char ch : chars) {
        char cur = e[ch];
        cyc[ch].push_back(cur);
        while (cur != ch) { cur = e[cur]; cyc[ch].push_back(cur); }
    }
    cin >> N >> l;
    for (char c : l) { j = (N-1) % (cyc[c].size()); ans += cyc[c][j]; }
    cout << ans << '\n';
}