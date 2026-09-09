#include <bits/stdc++.h>
using namespace std;
int a, b, c, arr[8];

int main() {
    cin >> a >> b >> c;
    arr[0] = (a+b+c); arr[1] = (a+b)*c; arr[2] = (a+c)*b; arr[3] = (b+c)*a; arr[4] = a*b*c;
    arr[5] = a*b+c; arr[6] = a*c+b; arr[7] = b*c+a;
    sort(arr, arr+8, greater<int>()); 
    cout << arr[0] << '\n';
}