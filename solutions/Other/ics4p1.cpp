#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

void permute(string a) {
    sort(a.begin(), a.end());
    do {
       cout << a << '\n';
    } while (next_permutation(a.begin(), a.end()));
}
  
int main() { 
    string s; cin >> s;
    permute(s); 
    return 0; 
}