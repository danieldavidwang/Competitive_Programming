#pragma GCC optimize ("Ofast, unroll-loops")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

double ans = 0, d = 0;

pair<short, short> cord[11];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        short x, y; cin >> x >> y;
        cord[i].first = x; cord[i].second = y;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                double a = sqrt((cord[j].first - cord[i].first) * (cord[j].first - cord[i].first) + (cord[j].second - cord[i].second) * (cord[j].second - cord[i].second));
                double b = sqrt((cord[k].first - cord[i].first) * (cord[k].first - cord[i].first) + (cord[k].second - cord[i].second) * (cord[k].second - cord[i].second));
                double c = sqrt((cord[k].first - cord[j].first) * (cord[k].first - cord[j].first) + (cord[k].second - cord[j].second) * (cord[k].second - cord[j].second));
                double semi = (a+b+c)/2;
                
                if ((semi == 0) || (a*a + b*b - c*c < 0) || (b*b + c*c - a*a < 0) || (c*c + a*a - b*b < 0)) {
        			if (a > d) d = a;
        			if (b > d) d = b;
        			if (c > d) d = c;
                }
                else d = 2*(a*b*c) / (4*sqrt((semi)*(semi-a)*(semi-b)*(semi-c)));
                if (ans < d) ans = d;
            }
        }
    }
    printf("%.2f", ans);
}