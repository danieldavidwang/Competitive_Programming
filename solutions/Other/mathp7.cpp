#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
long long N, sum = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;

	if (N==1) cout << 1 << '\n';
	else if (N==2) cout << 3 << '\n';
	else if (N==3) cout << 5 << '\n';
	else if (N==4) cout << 8 << '\n';
	else if(N==5) cout << 10 << '\n';
	else {
		long long r = N;
		sum = N;
		for (int i=2; i<=r; i++) {
			long long h = N/i;
			sum += h;
			if (h>i) {
				sum += i;
				sum += (r-h)*(i-1);
				r = h-1;
			}
			if (r<=i) break;
		}
        cout << sum << '\n';
	}
}