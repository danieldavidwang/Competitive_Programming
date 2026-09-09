#include <bits/stdc++.h>
using namespace std;
int N, stars = 0;
string s;

int main() {
    cin >> N >> s;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*') stars++;
        else {
            N -= (char(s[i]) - 96);
        }
    }
    // cout << N << '\n';
    
    if (stars*26 < N) { cout << "Impossible\n"; return 0; }
    else if (stars > N) { cout << "Impossible\n"; return 0; }
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*' && stars > 1) { 
            // cout << stars << '\n';
            if ((stars-1)*26 >= (N-1)) { s[i] = 'a'; N--; stars--; }
            else {
                int c = (N-((stars-1)*26));
                // if (c >= 27) { cout << "Impossible\n"; return 0; }
                s[i] = char(c+96);
                N -= c; stars--;
            }
            // cout << N << '\n';
        }
        else if (s[i] == '*' && stars == 1) {
            int c = N+96;
            // cout << c << '\n';
            // cout << char(c) << '\n';
            // if (c <= 96 || c >= 123) {
                // cout << "Impossible\n";
                // return 0;
            // }
            s[i] = char(c);
            break;
        } 
    }
    cout << s << '\n';
}

// 100
//ab*c*d*e**