#pragma GCC optimize ("Ofast")
#pragma GCC target ("fma,avx,avx2")

#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M, C, minn = 1000001, maxx = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    scan(N); scan(M); scan(C);

    if (M > N) {
        cout << "NONE" << '\n';
        return 0;
    }
 
    int a[N];
    int ai;
	
    for (int i=0; i<N; i++) {
        scan(ai);

        a[i] = ai;

        if (ai < minn) minn=ai;
        if (ai > maxx) maxx=ai;
    }

    if (M == 1) {
        for (int i = 0; i < N; i++) cout << a[i];
        return 0;
    }

    if (M == N) {
        if (C <= (maxx-minn)) cout << 0 << "\n";
        else cout << "NONE" << '\n';
    }
		
    vector<int> ans;
    int left = 0;
    int sampleCnt = 0;
    map<int, int> sm;
    
    int tmp;
    
    for (int right=0; right<N; right++) {
        ai = a[right];
        
        if (sm.find(ai) == sm.end()) {
            sm[ai] = 1;
        } else {
            sm[ai] = sm[ai]+1;
        }
        
        sampleCnt++;
        if (sampleCnt < M) continue;
        
        auto itr1 = sm.rbegin() -> first;
        auto itr2 = sm.begin() -> first;

        int md = (itr1) - (itr2);

        if (md <= C) {
            ans.push_back(left+1);
        }

        int al = a[left];
        tmp = sm[al];
        
        if (tmp > 1) {
            sm[al] = tmp-1;
        } else {
            sm.erase(al);
        }
                
        sampleCnt--;
        left++;
        if (left>=N) break;
    }
    
    if (ans.size()>0) {
        for (auto itr = ans.begin(); itr != ans.end(); itr++) cout << *itr << '\n';
    } else {
        cout << "NONE" << '\n';
    }
}