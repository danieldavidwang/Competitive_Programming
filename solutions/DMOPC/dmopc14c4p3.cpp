#pragma GCC optimize (2)
#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
const int MM = 1e3+3;
int r, c, Rdes, Cdes, leftA[MM][MM], rightA[MM][MM], a[MM][MM];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> c >> r;
    for (int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> a[i][j];
    
    cin >> Cdes >> Rdes;
    Cdes++; Rdes++;
    
    memset(leftA, INF, sizeof(leftA));
    memset(rightA, INF, sizeof(rightA));
    leftA[0][1] = 0;
    
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) leftA[i][j] = a[i][j] + min({leftA[i][j-1], leftA[i-1][j], rightA[i-1][j]});
        for (int j = c; j >= 1; j--) rightA[i][j] = a[i][j] + min({rightA[i][j+1], leftA[i-1][j], rightA[i-1][j]});
    }
    cout << min(leftA[Rdes][Cdes], rightA[Rdes][Cdes]) << '\n'; return 0;
}