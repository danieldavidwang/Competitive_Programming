#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <iostream>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n; scan(n);
    long long sum = 0;
    long long nums[n];
    
    for (long long i = 0; i < n; i++) {
        scan(nums[i]);
        sum += nums[i];
    }
    
    for (long long i = 0; i < (n-1); i++) {
        sum *= 2;
        sum = sum % 1000000007;
    }
    cout << sum;
}