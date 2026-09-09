#pragma GCC optimize (2)
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int N;
int table[1000][1000];
map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> table[i][j];
        }
    }
    int i0j0 = table[0][0];
    int i0jN = table[0][N-1];
    int iNj0 = table[N-1][0];
    int iNjN = table[N-1][N-1];

    m[i0j0] = i0j0;
    m[i0jN] = i0jN;
    m[iNj0] = iNj0;
    m[iNjN] = iNjN;

    int min = m.begin()->first;

    if(min == i0j0) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                printf("%d ", table[i][j] );
            }
            printf("\n");
        }
    }
    if(min == iNj0) {
        for(int j=0;j<N;j++) {
            for(int i=0;i<N;i++)
                printf("%d ", table[N-i-1][j] );
            printf("\n");
        }
    }
    if(min == i0jN) {
        for(int j=0;j<N;j++) {
            for(int i=0;i<N;i++)
                printf("%d ", table[i][N-j-1] );
            printf("\n");
        }
    }
    if(min == iNjN) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++)
                printf("%d ", table[N-i-1][N-j-1]);
            printf("\n");
        }
    }
    printf("\n");
}