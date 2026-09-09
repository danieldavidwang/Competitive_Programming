#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
const double PI = acos(-1);
vector<cd> roots;
vector<cd> invRoots;

void precomputeRoots(int n) {
    roots.resize(n);
    invRoots.resize(n);
    for (int i = 0; i < n; ++i) {
        double angle = 2 * PI * i / n;
        roots[i] = cd(cos(angle), sin(angle));
        invRoots[i] = conj(roots[i]);
    }
}

void fft(vector<cd> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int step = n / len;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len / 2] * (invert ? invRoots[j * step] : roots[j * step]);
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
            }
        }
    }

    if (invert) {
        for (cd &x : a)
            x /= n;
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    precomputeRoots(n);
    
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; ++i) result[i] = round(fa[i].real());
    return result;
}

string bigMultiply(const string &num1, const string &num2) {
    vector<int> a(num1.size()), b(num2.size());
    for (int i = 0; i < num1.size(); ++i) a[i] = num1[num1.size() - 1 - i] - '0';
    for (int i = 0; i < num2.size(); ++i) b[i] = num2[num2.size() - 1 - i] - '0';

    vector<int> result = multiply(a, b);
    string resultStr;
    int carry = 0;
    for (int i = 0; i < result.size(); ++i) {
        int sum = result[i] + carry;
        resultStr.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    while (carry) {
        resultStr.push_back((carry % 10) + '0');
        carry /= 10;
    }

    while (resultStr.size() > 1 && resultStr.back() == '0') resultStr.pop_back();
    reverse(resultStr.begin(), resultStr.end());
    return resultStr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string num1, num2;
    cin >> num1 >> num2;
    cout << bigMultiply(num1, num2) << '\n';

    return 0;
}