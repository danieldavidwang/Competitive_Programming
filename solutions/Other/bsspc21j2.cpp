#include <bits/stdc++.h>
using namespace std;
const int MM = 1441;
int M, N;
bool classes[MM], pass;

int main() {
    memset(classes, false, MM);
    cin >> M;
    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y;
        for (int j = x; j <= y; j++) classes[j] = true;
    }
    cin >> N;
    for (int i = 0, x, y; i < N; i++) {
        pass = true;
        cin >> x >> y;
        for (int j = x; j <= y; j++) {
            if (classes[j]) { pass = false; break; }
        }
        if (pass) cout << ":eyy:\n";
        else cout << "Break is Over! Stop playing games! Stop watching Youtube!\n";
    }
}