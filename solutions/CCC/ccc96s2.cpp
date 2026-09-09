#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

vector<short> nums;
int n;
string s;

void subStrings() {
	if (nums[0]==0) nums.erase(nums.begin());
	for (short i = 0; i < nums.size(); i++) cout << nums[i];
	cout << "\n";
	
	if (nums.size() > 2) {
		short last = nums[nums.size() - 1];
		nums.erase(nums.begin() + nums.size() - 1);
		for (short i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] < last) nums[i] = nums[i] + 10, nums[i - 1]--;
			nums[i] -= last;
			last = 0;
		}
		subStrings();
	}	
}

bool divisible11(string x) {
	nums = vector<short>();
	for (short i = 0; i < x.length(); i++) nums.push_back(x[i] - '0');
	
	subStrings();
	
	if ((nums.size() == 2) && (nums[0] * 10 + nums[1]) % 11 == 0) return true;
	else return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) { 
	    cin >> s;
	    if (i == n-1) {
    		if (divisible11(s)) {cout << "The number " << s << " is divisible by 11.\n";}
    		else {cout << "The number " << s << " is not divisible by 11.\n";}
	    } else {
	        if (divisible11(s)) {cout << "The number " << s << " is divisible by 11.\n\n";}
    		else {cout << "The number " << s << " is not divisible by 11.\n\n";}
	    }
	}
}