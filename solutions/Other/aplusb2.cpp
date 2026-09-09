#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;

string trim_lz(string s) {
    int pos = 0;
    while (pos < s.size()-1 && s[pos] == '0') pos++;
    return s.substr(pos);
}

int comp_abs(const string& a, const string& b) {
    string abs_a = a[0] == '-' ? a.substr(1) : a;
    string abs_b = b[0] == '-' ? b.substr(1) : b;
    abs_a = trim_lz(abs_a);
    abs_b = trim_lz(abs_b);
    if (abs_a.size() > abs_b.size()) return 1;
    if (abs_a.size() < abs_b.size()) return -1;
    for (int i = 0; i < abs_a.size(); ++i) {
        if(abs_a[i] > abs_b[i]) return 1;
        if(abs_a[i] < abs_b[i]) return -1;
    }
    return 0;
}

string add_str(const string& a, const string& b) {
    string s1 = a;
    string s2 = b;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string res = "";
    int carry = 0;
    int n = max(s1.size(), s2.size());
    for (int i = 0; i < n; ++i) {
        int digit1 = i < s1.size() ? s1[i]-'0' : 0;
        int digit2 = i < s2.size() ? s2[i]-'0' : 0;
        int total = digit1 + digit2 + carry;
        carry = total / 10;
        res += (total % 10) + '0';
    }
    if (carry) res += (carry + '0');
    reverse(res.begin(), res.end());
    return trim_lz(res);
}

string subtract_strings(const string& a, const string& b){
    string s1 = a;
    string s2 = b;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string res = "";
    int borrow = 0;
    for (int i = 0; i < s1.size(); ++i) { 
        int digit1 = s1[i]-'0';
        int digit2 = i < s2.size() ? s2[i]-'0' : 0;
        int sub = digit1 - digit2 - borrow;
        if(sub < 0){
            sub += 10;
            borrow = 1;
        }
        else borrow = 0;
        res += (sub + '0');
    }
    while(res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return trim_lz(res);
}

string add(const string& a, const string& b){
    bool neg_a = false, neg_b = false;
    string abs_a = a, abs_b = b;
    if (a[0] == '-') {
        neg_a = true;
        abs_a = a.substr(1);
    }
    if (b[0] == '-') {
        neg_b = true;
        abs_b = b.substr(1);
    }
    int cmp = 0;
    string trim_a = trim_lz(abs_a);
    string trim_b = trim_lz(abs_b);
    if(trim_a.size() > trim_b.size()) cmp = 1;
    else if(trim_a.size() < trim_b.size()) cmp = -1;
    else {
        cmp = 0;
        for(int i = 0; i < trim_a.size(); ++i){
            if(trim_a[i] > trim_b[i]){
                cmp = 1;
                break;
            }
            if(trim_a[i] < trim_b[i]){
                cmp = -1;
                break;
            }
        }
    }
    if (!neg_a && !neg_b) return add_str(trim_a, trim_b);
    if (neg_a && neg_b) {
        string sum = add_str(trim_a, trim_b);
        if(sum == "0") return "0";
        return "-" + sum;
    }
    if (!neg_a && neg_b) {
        if (cmp == 0) return "0";
        if (cmp > 0) {
            string diff = subtract_strings(trim_a, trim_b);
            return diff;
        }
        else {
            string diff = subtract_strings(trim_b, trim_a);
            return "-" + diff;
        }
    }
    if (neg_a && !neg_b) {
        if (cmp == 0) return "0";
        if (cmp > 0){
            string diff = subtract_strings(trim_a, trim_b);
            return "-" + diff;
        }
        else {
            string diff = subtract_strings(trim_b, trim_a);
            return diff;
        }
    }
    return "0";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    while(N--) {
        string num1, num2;
        cin >> num1 >> num2;
        string result = add(num1, num2);
        cout << result << "\n";
    }
}