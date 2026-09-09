#include <bits/stdc++.h>
using namespace std;
const int MM = 20;
int R, C, cc;
char puzzle[MM][MM+1];
char sol[MM+1] = "~"; char w[MM+1];

void adD(char x) {
    if(x!='#') w[cc++] = x;
    else {
        w[cc] = 0;
        if (cc >= 2 && strcmp(w, sol) < 0) strcpy(sol, w);
        cc = 0;
    } 
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) 
        cin >> puzzle[i];
    for (int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) 
            adD(puzzle[r][c]);
        adD('#');
    }
    for (int c = 0; c < C; c++) {
        for (int r = 0; r < R; r++) 
            adD(puzzle[r][c]);
        adD('#');
    }
    printf("%s\n", sol);
}