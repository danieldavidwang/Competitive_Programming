#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
using namespace std;

vector<bool> is_prime;
vector<int> primes;

bool crossout(long N) {
    long i=2;
    while(i*i <= N) {
        if(is_prime[i] == false) { 
            i++;
            continue;
        }
        long j = 2*i;
        while(j <= N) {
            is_prime[j] = false;
            j += i; 
        }
        i++;
    }
    return true;
}

bool crossoutMN(long M, long N) {
    long p = 0;
    long i = primes[0];
    while(i*i <= N && p<primes.size()) {
        long start = (M/i)*i;
        long j = start;
        while(j <= N) {
            if(j>=M && j!=i)
                is_prime[j-M] = false;
            j += i;
        }
        p++;
        i=primes[p];
    }
    return true;
}

bool isPrime(long number) {
    for(long i=0;i<primes.size();i++) {
        long p = primes[i];
        if(p*p > number) break;
        if(number % p == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    long M, N;
    cin >> M;
    cin >> N;
    
    is_prime.push_back(false);
    is_prime.push_back(false);

    long maxP = sqrt(N);
    for(long i=2; i<=maxP; i++) {
        is_prime.push_back(true);
    }
    crossout(maxP);
    for(long i=2;i<is_prime.size();i++) {
        if(is_prime[i]==true) {
            primes.push_back(i);
        }
    }
    if(M==1) M=2;
    
    for(long i=0; i<=maxP; i++) {
        is_prime[i]=(true);
    }        
    
    for(long i=M+maxP;i<=N;i++) {
        is_prime.push_back(true);
    }
    
    crossoutMN(M,N);
    
    for(long i=0;i<=N-M;i++) {
        if(is_prime[i]==true) {
            cout << M + i << '\n';
        }
    }
}