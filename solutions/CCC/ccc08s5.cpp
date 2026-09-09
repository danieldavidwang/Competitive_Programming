#include <bits/stdc++.h>
using namespace std;
bool winning[31][31][31][31];
int moves[5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
int n, A, B, C, D;

bool losing(int a, int b, int c, int d) {
    if (a < 0 || b < 0 || c < 0 || d < 0) return false;
	else return !winning[a][b][c][d];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cin >> n;
    for (int i = 0 ; i < 31 ; i++)
	    for (int j = 0 ; j < 31 ; j++)
		    for (int k = 0 ; k < 31 ; k++)
		        for (int l = 0 ; l < 31 ; l++)
			        for (int m = 0 ; m < 5 ; m++)
			            if (losing(i-moves[m][0], j-moves[m][1], k-moves[m][2], l-moves[m][3])) winning[i][j][k][l] = true;
	for (int i = 0; i < n; i++) {
	    cin >> A >> B >> C >> D;
	    if (winning[A][B][C][D]) cout << "Patrick\n";
	    else cout << "Roland\n";
	}
	return 0;
}