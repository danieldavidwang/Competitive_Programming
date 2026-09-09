#pragma GCC optimize (2)
#include "bits/stdc++.h"
using namespace std;
string alphabet, input_str;
set<string> output_set;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> alphabet >> input_str;
    for (int i = 0; i <= (int)input_str.length(); i++) {
        for (auto c : alphabet) {
            string inserted_str = input_str;
            inserted_str.insert(i, 1, c);
            output_set.insert(inserted_str);
        }
        if (i < (int) input_str.length()) {
            string deleted_str = input_str;
            deleted_str.erase(i, 1);
            output_set.insert(deleted_str);
            for (auto c : alphabet) {
                string replaced_str = input_str;
                replaced_str[i] = c;
                output_set.insert(replaced_str);
            }
        }
    }
    output_set.erase(input_str);
    for (auto result : output_set) cout << result << '\n';
    return 0;
}