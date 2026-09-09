#include <bits/stdc++.h>
using namespace std;
int h, m, t;
char ch;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> h >> ch >> m;
    t = 60*h+m;
    for(int i=240; i>0; t++) {
        if(t>=7*60 && t<10*60) i--;
        else if(t>=15*60 && t<19*60) i--;
        else i-=2;
    }
    printf("%02d%c%02d\n", t/60%24, ch, t%60);
}