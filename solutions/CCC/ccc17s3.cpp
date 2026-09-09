#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

const int maxS = 2009;
int N;
int wood[maxS] = {}; 
int board[maxS * 2] = {};
int counter = 1, maxLength = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> N;
	int x;
	
	while (N--) {
		cin >> x;
		wood[x]++;
	}
	
	for (int i = 1; i <= 2000; i++) {
		if (wood[i] > 0) {
			if (wood[i] > 1) {
				board[i * 2] += wood[i] / 2;
			}
			for (int j = i+1; j <= 2000; j++) {
				if (wood[j] != 0)
					board[i + j] += std::min(wood[i], wood[j]);
			}
		}	
	}
	
	for (int i = 1; i <= 4000; i++) {
		if (board[i] > maxLength) {
			maxLength = board[i];
			counter = 1;
		} else if (board[i] == maxLength) {
			counter++;
		}
	}
	
	cout << maxLength << " " << counter;
	
    return 0;
}