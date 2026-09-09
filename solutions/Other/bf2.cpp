#pragma GCC optimize (2)
#include<bits/stdc++.h>
using namespace std;
string str; int N;
 
void solve(string s) {
    string currStr = s.substr(0, N);
    string lexMin = currStr;

    for (int i = N; i < s.length(); i++) {
            currStr = currStr.substr(1, N) + s[i];
            if (lexMin > currStr) lexMin = currStr;    
        }
        cout << lexMin << '\n';
    }
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str >> N;
    solve(str);
}