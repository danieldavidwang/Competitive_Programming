#include <bits/stdc++.h>
using namespace std;
long long N, total = 0;
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> s;
        if (s[0] == 'P') total += 1500;
        else if (s[0] == 'M') total += 6000;
        else if (s[0] == 'S') total += 15500;
        else if (s[0] == 'C') total += 40000;
        else if (s[0] == 'T') total += 75000;
        else if (s[0] == 'H') total += 125000;
    }
    cout << total << '\n';
}