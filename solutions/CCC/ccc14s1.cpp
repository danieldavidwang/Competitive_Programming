#include <iostream>
#include <vector>

using namespace std;

vector<int> remove(vector<int> a, int num) {
    // a.shrink_to_fit();
    for (int k = a.size()-1; k >= 0; k--) {
        if ((k+1) % num == 0) {
            a.erase(a.begin()+(k));
        }
    }
    return a;
}

int main() {
    int K, m; 
    cin >> K;
    cin >> m;

    vector<int> people;
    int rounds[m];

    for (int i = 0; i < m; i++) {
        cin >> rounds[i];
    }

    for (int j = 0; j < K; j++) {
        people.push_back(j+1);
    }

    for (int l = 0; l < m; l++) {
        people = remove(people, rounds[l]);
    }
    
    for (auto itr = people.begin(); itr != people.end(); itr++) {
        cout << *itr << endl;
    }
}