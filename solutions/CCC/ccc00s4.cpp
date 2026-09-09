#include <bits/stdc++.h>
using namespace std;
int c[32], s[5281] = {-1}, d = 0, cc = 0, cnt = 0;

int solve(int a) {
	if (s[a] != -1) return s[a];
	int small = INT_MAX;
	for (int j = 0; j < cc; j++) {
		if (a - c[j] >= 0) {
			int calc = solve(a - c[j]);
			if (calc >= 0) small = min(small, calc);
		}
	}
	if (small != INT_MAX) return s[a] = small + 1;
	else return s[a] = -2;
}

int main() {
	cin >> d >> cc;
	memset(s, INT_MAX, sizeof(s));
	for (int i = 0; i < cc; i++) {
		cin >> c[i];
		s[c[i]] = 1;
	}
	cnt = solve(d);
	cout << (cnt <= -1 ? "Roberta acknowledges defeat." : "Roberta wins in " + to_string(cnt) + " strokes.") << "\n";
}