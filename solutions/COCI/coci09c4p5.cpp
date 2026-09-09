#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 10301
using namespace std;
int N, A, B, ret;
int memL[1024][1024][2];
int memR[1024][1024][2];

inline void add(int &a, int b) {
    a += b;
    if(a >= MOD) a -= MOD;
}

int recR(int n, int rub, bool gud) {
    int &ans = memR[n][rub][gud];
    if(ans != -1) return ans;

    ans = gud;
    if(rub <= n) add(ans, recR(n-rub, rub, true));
    if(n) add(ans, recR(n-1, rub+1, false));
    return ans;
}

int recL(int n, int rub, bool gud) {
    int &ans = memL[n][rub][gud];
    if(ans != -1) return ans;

    ans = 0;
    if(gud) add(ans, recR(n, B, true));
    if(rub <= n) add(ans, recL(n-rub, rub, true));
    if(n) add(ans, recL(n-1, rub+1, false));
    return ans;
}

int main() {
    memset(memL, -1, sizeof memL);
    memset(memR, -1, sizeof memR);
    cin >> N >> A >> B;
    ret = recL(N-A-B, A, true);
    cout << ret << '\n';
}