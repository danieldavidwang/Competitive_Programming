#pragma GCC optimize (2)
#include <bits/stdc++.h>
using namespace std;
bool flag = false;
int n, ans = 0;
stack<int> nums1, nums2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
	for(int i = 0, x; i < n; i++) {
		  cin >> x; nums1.push(x);
	}
	for(int i = 0, x; i < n; i++) {
	    cin >> x; nums2.push(x);
	}
	for(int i = 0; i < n; i++) {
		if(nums1.top() - nums2.top() == 0 && !flag) {
		    ans++;
		    flag = true;
		} else if (nums1.top() - nums2.top() != 0) flag = false;
		nums1.pop();
	    nums2.pop();
	}
    cout << ans << '\n';
}