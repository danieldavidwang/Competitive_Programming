#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

char isPossible() {
    vector<int> v2;
    int a = 1;

    for (int i = v.size()-1; i >= 0; i--) {
        bool alreadyPushed = false;
        if(v[i] == a) {
            a++;
            alreadyPushed = true;
        }
        while(v2.size() > 0 && v2[v2.size()-1] == a) {
            a++;
            v2.pop_back();
        }
        if(v2.size() > 0 && v[i] > v2[v2.size()-1]) {
            return 'N';
        }
        if(alreadyPushed == false) {
            if(v[i] == a) {
                a++;
            }
            else {
                v2.push_back(v[i]);
            }
        }
    }
    return 'Y';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int T; cin >> T >> N;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N; j++) {
            int k; cin >> k;
            v.push_back(k);
        }
        char x = isPossible();
        cout << x << '\n';
        v.clear();
        cin >> N;
    }
}