#pragma GCC optimize (2)
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    
    int timesa;
    double positionsa;
    map<int, double> tp;
    double speed = 0.0;
    double maxspeed = 0.0;

    for (int a = 0; a < N; a++) {
        cin >> timesa;
        cin >> positionsa;
        tp[timesa] = positionsa;
    }

    int count = 0;
    
    for (auto itr = tp.begin(); itr != tp.end();) {
        if(count ==  tp.size()-1) break;
            
        int t1 = (*itr).first;
        double p1 = (*itr).second;
    
        itr++;

        int t2 = (*itr).first;
        double p2 = (*itr).second;

        speed = abs((p2 - p1)) / abs((t2 - t1));

        if(maxspeed < speed) maxspeed = speed;
        count++;
    }
    cout << maxspeed;
}