#include <bits/stdc++.h>
using namespace std;
int minAns = INT_MAX, ans = 0, P, G, R, O, total;

int main() {
    cin >> P >> G >> R >> O >> total;
    for (int i = 0; i <= total; i++) {
        int Pval = i * P;
        for (int j = 0; j <= total; j++) {
            int Gval = j * G;
            for (int k = 0; k <= total; k++) {
                int Rval = k * R;
                for (int l = 0; l <= total; l++) {
                    int Oval = l * O;
                    if (Pval+Gval+Rval+Oval == total) {
                        if (i+j+k+l < minAns) minAns = i+j+k+l;
                        ans++;
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", i, j, k, l);
                    }
                }
            }
        }
    }
    printf("Total combinations is %d.\n", ans);
    printf("Minimum number of tickets to print is %d.\n", minAns);
}