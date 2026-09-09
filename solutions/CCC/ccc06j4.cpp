#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
vector<int> t(8); vector<vector<int>> pre(8);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    pre[1].push_back(7); t[7]++;
    pre[1].push_back(4); t[4]++;
    pre[2].push_back(1); t[1]++;
    pre[3].push_back(4); t[4]++;
    pre[3].push_back(5); t[5]++;
    
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        else {
            pre[a].push_back(b);
            t[b]++;
        }
    }
    priority_queue <int, vector<int>, greater<int> > priQ;
    queue<int> sequence;
    for (int i = 1; i <= 7; i++){
        if (t[i] == 0) priQ.push(i);
    }
    while (!priQ.empty()){
        int key = priQ.top();
        sequence.push(key);
        priQ.pop();
        for (int i = 0; i < pre[key].size(); i++){
            int tmp = pre[key][i];
            t[tmp]--;
            if (t[tmp] == 0) priQ.push(tmp);
        }
    }
    if (sequence.size() == 7){
        while (!sequence.empty()) {
            cout << sequence.front() << " ";
            sequence.pop();
        }
        cout << '\n';
    }  
    else cout << "Cannot complete these tasks. Going to bed.\n";
}