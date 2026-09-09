#pragma GCC optimize (2)

#include <bits/stdc++.h>

using namespace std;

const int maxx = 10e6+9;
long N;
vector<char> S;
vector<char> R;
string result = "";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        char c;
        cin >> c;
        S.push_back(c);
    }
    for(int i=0;i<N;i++) {
        R.push_back(S[N-i-1]);
    }


    for(int i=0;i<N;i++) {
        char f = S[0];
        char e = S[S.size()-1];
        if(f<e) {
            result = result + f;
            S.erase(S.begin());
            R.pop_back();
        } else if(f>e) {
            result = result + e;
            S.pop_back();
            R.erase(R.begin());
        } else {
            // cout << "equal," << "result" << result << endl;
            int count = 1;
            f = S[count];
            e = R[count];
            while(f == e && count*2 <= S.size()) {
                count++;
                f = S[count];
                e = R[count];                
            }
            if(f<=e) {
                result = result + S[0];
                S.erase(S.begin());
                R.pop_back();
            } else {
                result = result + R[0];
                S.pop_back();
                R.erase(R.begin());
            }
        }
    }
    cout << result;
    return 0;
}