#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 100;
int M, Q, times[MM+1], best[MM+1], g[MM+1], l[MM+1], totalT = 0;
string names[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> names[i];
        cin >> times[i];
    }
    for (int i = 1; i <= Q; i++) {
        best[i] = 2000000;
        g[i] = -1;
    }
    for (int i = 0; i <= Q; i++) {
        int curr = 0;
        for (int j = 1; (j <= M) && (i+j-1 < Q); j++) {
            curr = max(curr, times[i+j-1]);
            if (best[i]+curr < best[i+j]) {
                best[i+j] = best[i]+curr;
		        g[i+j] = j;
            }
        }
    }
    cout << "Total Time: " << best[Q] << '\n';
    int p = Q;
    int a = 0; 
    while (g[p]) {
        l[a++] = g[p];
        p -= g[p];
    }
    int b = 0;
    for (int i = a-1 ; i >= 0 ; i--) {
	    for (int j = 0 ; j < l[i] ; j++)
		    cout << names[b++] + " ";
	    cout << '\n';
	}
	return 0;
}