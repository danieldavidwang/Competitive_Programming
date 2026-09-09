#pragma GCC optimize ("Ofast, unroll-loops")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

const int MM = 1e6+2;
int arr[MM + 1];
vector<int> factorCount[MM/10];
map<long long, int> myMap;

int K, A, B;
 
void solve() {
    arr[0] = -1;
    arr[1] = -1;

    for (int i = 2; i <= (MM)/2; i++) {
        for (int j = i; j <= MM; j += i) {
            arr[j]++;
        }
    }
 
    for (int i = 1; i <= MM; i++)
    {
        factorCount[arr[i]].push_back(i);
    }
}


int getIndex(int factornumber, int n) {
    vector<int> v = factorCount[factornumber];
    if(n <= 0) {
        n = 1;
    }
    if(v.size() == 0 ) return -1;
    if(v.size() == 1) {
        if(v[0]<=n)
            return 0;
        else
            return -1;
    }
    int high = v.size()-1;
    int low = 0;
    while(low <= high) {
        int mid = (low+high) / 2;
        if(v[mid] == n)
            return mid;
        else if(n > v[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    if(v[low] <= n) 
        return low;
    if(low>0 && v[low-1] <= n) 
        return low-1;
    else
        return -1;
}
 
int getCachedIndex(int factornumber, int n) {
    long long key = factornumber * 10000000 + n;
    if(myMap.find(key) != myMap.end()) {
        return myMap[key];
    }
    else {
        int ret = getIndex(factornumber, n);
        myMap[key] = ret;
        return ret;
    }
}

int main() {
    int Q; cin >> Q;
    solve();
    for (int i = 0; i < Q; i++) {
        int counter = 0;
        scan(K); scan(A); scan(B);
        int fn = K - 1;

        if(K == 1) {
            if(A == 1) 
                counter = 1; 
            else 
                counter = 0;
        }
        else {
            int Aindex=0, Bindex=0;
            Aindex = getCachedIndex(fn, A-1);
            Bindex = getCachedIndex(fn, B);
            if(Aindex == -1 && Bindex == -1 ) counter = 0;
            if(Aindex == -1 && Bindex >= 0 ) counter = Bindex + 1;
            if(Aindex >= 0 && Bindex >= 0 ) counter = Bindex - Aindex;
        }
        printf("%d\n",counter);
    }
}