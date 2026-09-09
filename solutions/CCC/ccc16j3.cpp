#pragma GCC optimize (2)

#include <bits/stdc++.h>
using namespace std;

int longestPal(string str) {
    int n = str.size();
    if (n < 2) return n;
 
    int maxl = 1, start = 0;
    int low, h;
    for (int i = 0; i < n; i++) {
        low = i - 1;
        h = i + 1;
        while ((h < n) && (str[h] == str[i])) h++;
 
        while ((low >= 0) && (str[low] == str[i])) low--;
 
        while ((low >= 0) && (h < n) && (str[low] == str[h])) {
            low--;
            h++;
        }
 
        int l = h - low - 1;
        if (maxl < l) {
            maxl = l;
            start = low + 1;
        }
    }
    return maxl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    int x = longestPal(s);
    cout << x;
    return 0;
}