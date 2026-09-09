#include <bits/stdc++.h>
using namespace std;
int n, l;
string s, t;

int main() {
    cin >> n >> l; cin.ignore(); getline(cin, s);
    for(int i = 0; i < n; i++) {
        if (s[i] == ' ') { t += " "; continue; }
        t += (s[i]-'a'+l)%26+'a';
    }
    cout << t << endl;
}