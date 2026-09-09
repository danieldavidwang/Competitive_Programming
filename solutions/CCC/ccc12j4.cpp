#include <bits/stdc++.h>
using namespace std;
int k;
string s;

int main() {
    cin >> k >> s;
    for (int i=0; i< s.length(); i++){
        int decode = s[i]-3*(i+1)-k;
        if(decode < 'A') decode += 26;
        s[i] = decode;
    }
    cout << s << '\n';
}