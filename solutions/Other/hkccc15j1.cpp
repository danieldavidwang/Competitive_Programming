#include <bits/stdc++.h>
using namespace std;
int N, a=0, b=0;
string seq1[101], seq2[101];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> seq1[i];
    for (int i = 0; i < N; i++) cin >> seq2[i];
    for (int i = 0; i < N; i++) {
        if (seq1[i][0] == seq2[i][0]) continue;
        else if (seq1[i][0] == 'p' && seq2[i][0] == 'r') a++;
        else if (seq1[i][0] == 'r' && seq2[i][0] == 's') a++;
        else if (seq1[i][0] == 's' && seq2[i][0] == 'p') a++;
        else b++;
    }
    cout << a << " " << b << '\n';
}