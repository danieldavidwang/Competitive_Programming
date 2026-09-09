#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+1;
int N, ammo = 0, score = 0, opAmmo[MM];
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> s;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            if (s[i] == 'R') opAmmo[0] = 1;
            else opAmmo[0] = 0;
        }
        else {
            opAmmo[i] = opAmmo[i-1];
            if (s[i] == 'R') opAmmo[i] += 1;
            if (s[i] == 'F') {
                if (opAmmo[i-1] > 0) { opAmmo[i] -= 1; }
                else opAmmo[i] = 0;
            }
        }
    }
    
    // for (int i = 0; i < N; i++) {
    //     cout << opAmmo[i] << "  ";
    // }
    
    for (int i = 0; i < N; i++) {
        // cout << "my ammo: " << ammo << '\n';
        // cout << "my score: " << score << '\n';
        // cout << "________" << '\n';
        if (s[i] == 'B') ammo++;
        else if (s[i] == 'R') {
            if (ammo > 0) {
                ammo--; score++;
            }
            else {
                ammo++; 
            }
        }
        else if (s[i] == 'F') {
            if (opAmmo[i-1] == 0 && ammo > 0) {
                ammo--; score++;
            }
            else if (opAmmo[i-1] == 0 && ammo == 0) ammo++;
        }
    }
    cout << score << '\n';
    return 0;
}