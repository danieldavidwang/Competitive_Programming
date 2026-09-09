#pragma GCC optimize (2)

#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int h;
int numHydrants;
vector<int> houses;

int maxLength = 1000000, minLength = 0;

int getHydrantsNeeded(int hoseLength){
    int minHydrants = 1000000;
    int hoseSpan = hoseLength * 2;

    for(int i = 0; i<h; i++){
        int neededHydrants = 1;
        int currentHouse = (i+1) % h;
        int hoseLeft = hoseSpan;

        while(currentHouse != i){
            int dist;
            if(currentHouse == 0){
                dist = 1000000 + houses[0] - houses[h-1];
            } else {
                dist = houses[currentHouse] - houses[currentHouse-1];
            }
            
            if(dist > hoseLeft){
                hoseLeft = hoseSpan;
                neededHydrants++;
            } else {
                hoseLeft -= dist;
            }

            currentHouse = (currentHouse + 1) % h;
        }
        minHydrants = min(minHydrants, neededHydrants);
    }
    return minHydrants;
}

int main(){
    ios_base::sync_with_stdio(0);
    
    scan(h);
    
    for(int i = 0, x; i<h; i++){
        scan(x);
        houses.push_back(x);
    }

    scan(numHydrants);
    sort(houses.begin(), houses.end());

    while(maxLength > minLength){
        int mid = (maxLength + minLength)/2;
        int hydrantsNeeded = getHydrantsNeeded(mid);
        if(hydrantsNeeded > numHydrants){
            minLength = mid + 1;
        } else {
            maxLength = mid;
        }
    }

    cout << minLength << '\n';
}