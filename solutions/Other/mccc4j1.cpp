#include <bits/stdc++.h>
using namespace std;
int F, M, B, t1, t2, t3;

int main() {
    cin >> F >> M >> B >> t1 >> t2 >> t3;
    cout << t1+t2+t3 << " " << F*t1+M*t2+B*t3 << '\n';
}