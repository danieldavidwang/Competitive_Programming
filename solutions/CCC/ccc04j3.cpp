#include <bits/stdc++.h>
using namespace std;
int n, m;
string adj[6];
string noun[6];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> adj[i];
    for (int i = 0; i < m; i++)
        cin >> noun[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << adj[i] << " as " << noun[j] << '\n';
        }
    }
}