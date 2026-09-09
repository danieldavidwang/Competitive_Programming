#include <bits/stdc++.h>
using namespace std;
double N, M, Y;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> Y;
    for (int i = 0; i <= Y; i++) {
        cout << i << " " << std::fixed << setprecision(2) << N << '\n';
        N *= 1+(M/100);
    }
}