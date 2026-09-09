#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N;
double price[MM], dp[MM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> price[i];
    for (int i = 1; i <= N; i++) {
	    dp[i] = dp[i-1]+price[i];
		if (i>1) dp[i] = min( dp[i], dp[i-2] + max(price[i-1], price[i]) + (min(price[i-1], price[i])/2) );
		if (i>2) dp[i] = min( dp[i], dp[i-3] + max(price[i-1], price[i]) + max(min(price[i-1], price[i]), price[i-2]) );
    }
    printf("%.1f", dp[N]);
}