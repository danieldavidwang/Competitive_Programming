#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

string sentence;
int num;
vector<int> freq[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getline(cin, sentence);
    cin >> num;
    
    for (int i = 0; i < sentence.length(); i++) {
        char cc = sentence[i];
        if (cc == ' ') continue;
        int indexC = cc - 'a';
        freq[indexC].push_back(i+1);
    }
    
    for (int i = 0; i < num; i++) {
        int num2, num3; cin >> num2 >> num3;
        char c; cin >> c;
        int x = c - 'a';
        cout << upper_bound(freq[x].begin(), freq[x].end(), num3)-lower_bound(freq[x].begin(), freq[x].end(), num2) << '\n';
    }
}