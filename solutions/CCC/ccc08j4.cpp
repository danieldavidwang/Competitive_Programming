#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> s(const string &input, char delimiter) {
    vector<string> vals;
    string val;
    for (char c : input) {
        if (c == delimiter) {
            if (!val.empty()) {
                vals.push_back(val);
                val.clear();
            }
        } else {
            val += c;
        }
    }
    if (!val.empty()) {
        vals.push_back(val);
    }
    return vals;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input;
    while (getline(cin, input) && input != "0") {
        vector<string> vals = s(input, ' ');
        for (int i = vals.size() - 1; i >= 0; --i) {
            if (vals[i] == "+" || vals[i] == "-") {
                vals[i] = vals[i + 1] + " " + vals[i + 2] + " " + vals[i];
                vals.erase(vals.begin() + i + 2);
                vals.erase(vals.begin() + i + 1);
            }
        }
        cout << vals[0] << "\n";
    }
    return 0;
}