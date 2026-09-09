#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int x, y, screen_x = 0, screen_y = 0;
	int bx, by;
	cin >> bx >> by;
	cin >> x >> y;
	
	while (x != 0 || y != 0) {
		if (screen_x + x >= bx) x = bx - screen_x;
		if (screen_x + x <= 0) x = -screen_x;
		if (screen_y + y >= by) y = by - screen_y;
		if (screen_y + y <= 0) y = -screen_y;

		screen_x += x; screen_y += y;
		cout << screen_x << " " << screen_y << "\n";
		cin >> x >> y;
	}
}