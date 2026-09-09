#pragma GCC optimize (2)
#include <iostream>
using namespace std;
short N, M, a, b, start, last;
bool adj[2020][2020];
bool visited[2020];

void depth(short i) {
    visited[i] = true;
    for (short j = 1; j <= N; j++) {
        if ((adj[i][j]) && (!visited[j])) depth(j);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> a >> b;
    for (short i = 0; i < M; i++) {
        cin >> start >> last;
        adj[start][last] = true; adj[last][start] = true;
    }
    depth(a);
    if (visited[b]) cout << "GO SHAHIR!" << '\n';
    else cout << "NO SHAHIR!" << '\n';
}