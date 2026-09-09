#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include <iostream>
#include <vector>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int x;

int main() { scan(x); printf("%d\n", x*(x-1)); }