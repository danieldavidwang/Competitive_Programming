#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+100;
long long arr[MM+1];
long long cal[MM+1];
long long N, K, X;

long long getXX() {
    // long long res = 0;
    for(int i=0;i<N;i++) {
        cal[i] = arr[i];
    }
    for(int i=0;i<N-1;i++) {
        for(int j=0;j<N-i-1;j++) {
            cal[j] = (cal[j] + cal[j+1]) % K;
        }
    }
    return cal[0] % K;
}

long long getX() {
    long long twoPower = 1;
    for(int i=0;i<N-1;i++) {
        twoPower = twoPower * 2;
        twoPower = twoPower % K;
    }
    // cout << "twoPower is:" << twoPower << "\n";
    return (twoPower * (K-1)) % K;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> X;

    for(int i=0;i<N;i++) {
        arr[i] = K - 1;
    }
    for(int i=0;i<K;i++) {
        long long resultX = getX();
        if(resultX == X)
            break;
        else {
            long long dif = resultX - X + K;
            dif = dif % K;
            // cout << "dif is:" << dif << '\n';
            arr[N-1] = arr[N-1] - dif;
            break;
        }
    }
    for(int i=0;i<N;i++) {
        cout << arr[i];
        if(i<N-1)
            cout << " ";
    }
    cout << '\n';
    return 0;
}