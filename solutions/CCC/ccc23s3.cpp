#pragma GCC optimize ("Ofast, unroll-loops")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+3;
int N, M, R, C;
char a[MM][MM];

void outA() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

void doFlip(int flipR, int flipC) {
    int flipCount = min(flipR,flipC);
    int i=1;
    int midN = 0;
    int midM = 0;
    if(N % 2 == 1) {
        midN = N / 2 + 1;
    }
    if(M % 2 == 1) {
        midM = M / 2 + 1;
    }

    for(;i<=flipCount;i++) {
        a[i][i] = 'f';
        if(i == midN) a[i-1][i] = 'h';
        if(i == midM) a[i][i-1] = 'h';
    }
    int flipR_left = flipR - flipCount;
    int flipC_left = flipC - flipCount;
    i = flipCount + 1;
    while(flipR_left > 0) {
        a[i][1] = 'g';
        flipR_left --; i++;
    }
    while(flipC_left > 0) {
        a[1][i] = 'g';
        flipC_left --; i++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    memset(a,'a',sizeof(a));
    cin >> N >> M >> R >> C;
    int midN = N / 2;
    int midM = M / 2;
    if (N % 2 == 0) {
        for(int i=1;i<=M;i++) {
            a[midN][i] += 1;
            a[midN+1][i] += 1;
        }
    }
    
    else {
        for(int i=1;i<=M;i++) {
            a[midN+1][i] += 1;
        }
    }
    if(M % 2 == 0) {
        for(int i=1;i<=N;i++) {
            a[i][midM] += 1;
            a[i][midM+1] += 1;
        }
    }
    
    else {
        for(int i=1;i<=N;i++) {
            a[i][midM+1] += 1;
        }
    }

    if(N == R && M == C) {
        outA();
        return 0;
    }
    int flipR = N - R;
    int flipC = M - C;
    if(N % 2 == 0 && M % 2 == 0) {
        if(N == R) {
            if (flipC % 2 == 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
            else {
                for(int i=1;i<=flipC/2;i++) {
                    a[1][i] = 'f';
                    a[1][M-i+1] = 'f';
                }
            }
            outA();
            return 0;
        }
        if (M == C) {
            if (flipR % 2 == 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
            else {
                for (int i=1;i<=flipR/2;i++) {
                    a[i][1] = 'f';
                    a[N-i+1][1] = 'f';
                }
            }
            outA();
            return 0;            
        }
        doFlip(flipR,flipC);
        outA();
        return 0;            
    }
    else if (N % 2 == 1 && M % 2 == 1) {
        if (N == R) {
            if(flipC % 2 == 1) {
                a[1][midM+1] = 'f';
                flipC--;
            }
            for (int i=1;i<=flipC/2;i++) {
                a[1][i] = 'f';
                a[1][M-i+1] = 'f';
            }
            outA();
            return 0;
        }
        if (M == C) {
            if (flipR % 2 == 1) {
                a[midN+1][1] = 'f';
                flipR--;
            }
            for (int i=1;i<=flipR/2;i++) {
                a[i][1] = 'f';
                a[N-i+1][1] = 'f';
            }
            outA();
            return 0;         
        }
        doFlip(flipR,flipC);
        outA();
        return 0;        
    }
    else if (N % 2 == 0 && M % 2 == 1) {
        if(N == R) {
            if(flipC % 2 == 1) {
                a[1][midM+1] = 'f';
                flipC--;
            }
            for(int i=1;i<=flipC/2;i++) {
                a[1][i] = 'f';
                a[1][M-i+1] = 'f';
            }
            outA();
            return 0;
        }
        if(M == C) {
            if(flipR % 2 == 1) {
                cout << "IMPOSSIBLE";
                return 0;                
            }
            for(int i=1;i<=flipR/2;i++) {
                a[i][1] = 'f';
                a[N-i+1][1] = 'f';
            }
            outA();
            return 0;         
        }
        doFlip(flipR,flipC);
        outA();
        return 0;        
    }
    else if(N % 2 == 1 && M % 2 == 0) {
        if(N == R) {
            if(flipC % 2 == 1) {
                cout << "IMPOSSIBLE";
                return 0;                
            }
            for(int i=1;i<=flipC/2;i++) {
                a[1][i] = 'f';
                a[1][M-i+1] = 'f';
            }
            outA();
            return 0;
        }
        if(M == C) {
            if(flipR % 2 == 1) {
                a[midN+1][1] = 'f';
                flipR--;
            }
            for(int i=1;i<=flipR/2;i++) {
                a[i][1] = 'f';
                a[N-i+1][1] = 'f';
            }
            outA();
            return 0;         
        }
        doFlip(flipR,flipC);
        outA();
        return 0;        
    }
    outA();
    return 0;
}