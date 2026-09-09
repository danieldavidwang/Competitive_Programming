#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
int N, K, diff, freq[26];
char freqMin;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> s;
    for (char c : s) freq[c-'a']++;
    int i = N+1;
    for (int j = 0; j < 26; j++) if (freq[j] < i) { i = freq[j];  freqMin = (char)(j + 'a'); }
    
    if (K > N || K < i) { cout << "WRONGANSWER\n"; return 0; }
    diff = K - i;
    for (char c : s) {
        if (diff > 0) { cout << c; if (c != freqMin) diff--; }
        else cout << freqMin;
    }
    cout << '\n';
}