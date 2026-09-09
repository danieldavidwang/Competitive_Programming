#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool DEBUG = false;
int M, N;
const int MAX_LINE = 1002;
int room[MAX_LINE][MAX_LINE];


class BoardPos {
    public:
    int x=0;
    int y=0;
};

unordered_map<int,vector<BoardPos>> mapCheck;
unordered_map<string,BoardPos> mapVisited;


bool canRun(int value) {
    vector<BoardPos> vb = mapCheck[value];
    if(DEBUG)
        cout << "size of vb is:" << vb.size() << endl;

    for(auto itr=vb.begin();itr!=vb.end();itr++) {
        int i = itr->x; 
        int j = itr->y;
        if(i == 0 && j==0)
            return true;
        string key = to_string(i+1) + "," + to_string(j+1) + "," + to_string(value);
        if(mapVisited.find(key) == mapVisited.end()) {
            mapVisited[key] = *itr;
            int nextValue = (i+1)*(j+1);
            bool nextTry = canRun(nextValue);
            if(nextTry == false)
                continue;
            else
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M;
    cin >> N;

    int val = M * N;

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            int value;
            cin >> value;
            room[i][j] = value;
            if(mapCheck.find(value) ==  mapCheck.end()) {
                mapCheck[value];
            }            
            BoardPos bp;
            bp.x = i; bp.y=j;
            mapCheck[value].push_back(bp);
        }
    }
    if(canRun(val) == true) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    
    return 0;
}