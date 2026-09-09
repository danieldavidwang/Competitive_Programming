#pragma GCC optimize (2)
#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;
const int MM = 25, MS = 1 << MM;
int num, bit, state = 0;
bool visited[MS];
deque<pair<int, int>> next_states;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> bit;
        state += (bit << i);
    }

    visited[state] = 1;
    next_states.push_back({state, 0});

    while (!next_states.empty()) {
        auto current = next_states.front();
        next_states.pop_front();

        if (current.first == 0) {
            cout << current.second << '\n';
            return 0;
        }

        for (int i = 0; i < num; i++) {
            if (!((current.first >> i) & 1)) {
                int new_state = current.first | (1 << i), streak = 0;
                for (int j = 0; j < num; j++) {
                    if ((new_state >> j) & 1) streak++;
                    else {
                        if (streak >= 4) for (int k = j - streak; k < j; k++) new_state &= ~(1 << k);
                        streak = 0;
                    }
                }

                if (streak >= 4) for (int j = num - streak; j < num; j++) new_state &= ~(1 << j);

                if (!visited[new_state]) {
                    visited[new_state] = 1;
                    next_states.push_back({new_state, current.second + 1});
                }
            }
        }
    }
}