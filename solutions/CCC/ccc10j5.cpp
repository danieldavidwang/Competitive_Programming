#pragma GCC optimize (2)

#include <bits/stdc++.h>

using namespace std;

pair<int, int> c1;
pair<int, int> c2;
int lvl = 0; 

pair<int, int> moves[8] = {make_pair(-1, 2), make_pair(-2, 1), make_pair(-2, -1), make_pair(-1,-2), make_pair(1, 2), make_pair(2, 1), make_pair(2, -1), make_pair(1, -2)};

set<pair<int, int> > visited;

class Node {
    public:
        pair<int, int> point;
        int lvl;

    Node(pair<int,int> p, int l) {
        point = p;
        lvl = l;
    }    
};

queue<Node> q;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    c1.first = x1; c1.second = y1;
    c2.first = x2; c2.second = y2;
    
    if (c1 == c2) {
        cout << 0;
        return 0;
    }
    
    Node nd(c1, 0);
    q.push(nd);
    visited.insert(c1);
    
    while (q.empty() != 1) {
        nd = q.front();
        pair<int, int> currentPos = nd.point;
        q.pop();
        
        if (currentPos == c2) {
            cout << nd.lvl << '\n';
            return 0;
        }
        
        for(int i = 0; i < 8; i++) {
            if ((currentPos.first+moves[i].first<=0) || (currentPos.second+moves[i].second<=0)) continue;
            else if ((currentPos.first+moves[i].first>8) || (currentPos.second+moves[i].second>8)) continue;
            else {
                pair<int, int> newP = make_pair(currentPos.first+moves[i].first, currentPos.second+moves[i].second);
                if (visited.find(newP) != visited.end()) continue;
                else {
                    Node new_nd = Node(newP, nd.lvl+1);
                    visited.insert(newP);
                    q.push(new_nd);
                }
            }
        }
    }
}