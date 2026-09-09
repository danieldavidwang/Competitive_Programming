#pragma GCC optimize (2)

#include <bits/stdc++.h>

using namespace std;

const int maxx = 10e6+9;
long long N, K;
long long counter = 0;
int arr[maxx];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N; cin >> K;
    
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    if (K == 0) {
        cout << 0;
        return 0;
    }

    if (K == 1) {
        cout << N*(N+1)/2;
        return 0;
    }

    long long flavours = 0;
    long long l = 0;
    long long r = 0;
    bool mvRight = true;
    map<int, int> mm;

    while (r < N) {
        int rf = arr[r];
        int lf = arr[l];

        if (mvRight) {
            if (mm.find(rf) == mm.end()) {
                mm[rf] = 1;
                flavours++;
            } else {
                mm[rf]++;
            }
        }

        // cout << "size of map is: " << mm.size() << endl;
        // cout << "right = " << r << '\n';

        if (flavours >= K) {
            counter += (N-r);
            l++;

            int lv = mm[lf];

            if (lv == 1) {
                mm.erase(lf);
                flavours--;
            } else {
                mm[lf] = lv-1;
            }
            mvRight = false;
        }
        
        else {
            r++;
            mvRight = true;
        }
    }

    cout << counter;
    
    return 0;
}