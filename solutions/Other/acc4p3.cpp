#include <bits/stdc++.h>
using namespace std;

bool f(int n){
    int squareRoot = sqrt(n);
    if (squareRoot * squareRoot == n) return true;
    else return false;
}