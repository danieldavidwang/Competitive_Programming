#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    vector<int> even;
    vector<int> odd;
    vector<int> sequence;
   
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
   
    if (N >= 8) {
        for (int j = 0; j < odd.size(); j++) {
            sequence.push_back(odd[odd.size()-j-1]);
        }
       
        sequence.push_back(8);
        even.erase(even.begin()+3);
       
        for (int k = 0; k < even.size(); k++) {
            sequence.push_back(even[k]);
        }
        for (auto itr = sequence.begin(); itr != sequence.end();) {
            int num = *itr;
            itr++;
            if(itr==sequence.end()) {
                cout << num;
                break;
            } else {
                cout << num << " ";
            }
        }
    }
   
    else if (N == 1) {
        cout << 1;
    } else if (N == 2) {
        cout << -1;
    } else if (N == 3) {
        cout << -1;
    } else if (N == 4) {
        cout << -1;
    } else if (N == 5) {
        cout << "2 4 5 3 1";
    } else if (N == 6) {
        cout << "2 6 4 5 1 3";
    } else if (N == 7) {
        cout << "7 2 4 6 3 5 1";
    }
    cout << '\n';
}