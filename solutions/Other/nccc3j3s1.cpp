#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
map<int, int> freq;
string s;
int max1=0, max2=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (freq.find(c) == freq.end()) freq[c] = 0;
        freq[c]++;
    }
    for (auto itr = freq.begin(); itr != freq.end(); itr++) {
        if (itr->second > max1) { max2 = max1; max1 = itr->second; }
        else if (itr->second > max2) { max2 = itr->second; }
    }
    cout << s.length()-max1-max2 << '\n';
}