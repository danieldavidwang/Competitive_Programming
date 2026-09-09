#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        string tmp = "";
        for (auto item : s) {
            if (item == ' ') {
                if (tmp.length() == 4)
                    cout << "**** ";
                else
                    cout << tmp + ' ';
                tmp = "";
            } else
                tmp += item;
        }
        if (tmp != "") {
            if (tmp.length() == 4)
                cout << "****";
            else
                cout << tmp;
        }
        cout << endl;
    }
}