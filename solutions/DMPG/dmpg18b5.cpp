#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
string s;
int k;

int cntSubstrings(string s, int k) {
    int n = s.length();
    int cnt = 0;
    int st = 0;
    int end = 0;
    int uniqCharcnt = 0;
    int charcnt[26] = {0};
    
    while (end < n) {
        charcnt[s[end] - 'a']++;
        if (charcnt[s[end] - 'a'] == 1) uniqCharcnt++;
        while (uniqCharcnt > 1 || end - st + 1 > k) {
            charcnt[s[st] - 'a']--;
            if (charcnt[s[st] - 'a'] == 0) uniqCharcnt--;
            st++;
        }
        if (end - st + 1 == k && uniqCharcnt == 1) cnt++;
        end++;
    }
    return cnt;
}

int main() {
    cin >> s >> k;
    cout << cntSubstrings(s, k) << '\n';
    return 0;
}