#include <bits/stdc++.h>
using namespace std;
string in; int cnt=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getline(cin, in);
    for (int i = 0; i < in.length(); i++) {
        if(in[i] == 't' || in[i] == 'T') {
            cnt++;
        }
    }
    cnt%2==0?(cout << "False\n"):(cout<<"True\n");
}