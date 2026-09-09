#include <stdio.h>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main() {
    int maxNum = 0;
    int G; scan(G);
    int P; scan(P);
    
    int planes;
    int docksNext[500001];

    for (int i = 0; i < G+1; i++) {
        docksNext[i] = i;
    }

    for (int i = 0; i < P; i++) {
        scan(planes);
        int pos = 0;
        while (planes != docksNext[planes]) {
            if (pos != 0) {
                docksNext[pos] = docksNext[planes];
            }
            pos = planes;
            planes = docksNext[planes];
        }
        if (planes == 0)
            break;
        else {
            maxNum++;
            docksNext[planes] = planes - 1;
        }
    }
    printf("%d", maxNum);
}