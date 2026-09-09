#pragma GCC optmize (2)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e4+9;
ll T,N;
string s[MM];
int a[26*2+1];

void outputA(int a[]) {
    for(int i=0;i<6;i++) {
        cout << a[i];
    }
    cout << endl;
}

char alternate(string s) {
    char res = 'T';
    for(int j=0;j<26;j++) {
        a[j]=0;
    }
    // cout << "N is:" << N << endl;
    for(ll i=0;i<N;i++) {
        int index = s[i] - 'a';
        // cout << "index is:" << index << endl;
        if(a[index] <= 1) {
            a[index] = a[index] + 1;
        }
    }
    // outputA(a);
    for(ll i=0;i<N;i++) {
        int indexA = s[i] - 'a';
        int indexB = s[i+1] - 'a';
        if(a[indexA] == a[indexB]) {
            res = 'F';
            break;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T >> N;
    for(ll i=1;i<=T;i++) {
        cin >> s[i];
    }
    for(ll i=1;i<=T;i++) {
        cout << alternate(s[i]) << endl;
    }
    return 0;
}