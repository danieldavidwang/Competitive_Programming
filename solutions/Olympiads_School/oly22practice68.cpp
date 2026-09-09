#include <bits/stdc++.h>

using namespace std;

string pass;
string arr[20] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> pass;
    
    if ((pass[0] == pass[1]) && (pass[1] == pass[2]) && (pass[2] == pass[3])) {
        cout << "weak";
        return 0;
    }
    
    for(int i = 0; i < 16; i++) {
        string a = arr[i]; string b = arr[i+1]; string c = arr[i+2]; string d = arr[i+3];
        string abcd = a+b+c+d;
        string dcba = d+c+b+a;
        if ((abcd == pass) || (dcba == pass)) {
            cout << "weak";
            return 0;
        }
    }
    cout << "strong";
}