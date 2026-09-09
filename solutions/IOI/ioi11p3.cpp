#include <bits/stdc++.h>
using namespace std;
long long leftIndex, rightIndex, frontIndex, backIndex, middleIndex, maxDiff;

int besthub(int num, int length, int elements[], long long maxDifference) {
    vector<long long> queueValues(100010);
    long long curDiff = 0;

    while (leftIndex < num && rightIndex < num) {
        while (rightIndex <= num && curDiff <= maxDifference) {
            maxDiff = max(maxDiff, backIndex - frontIndex);
            if (rightIndex < num) {
                if ((frontIndex ^ backIndex) > 0) curDiff += (elements[rightIndex] - queueValues[middleIndex]);
                queueValues[backIndex] = elements[rightIndex];
                backIndex++;
                if (middleIndex < (backIndex + frontIndex) / 2) middleIndex++;
            }
            rightIndex++;
        }
        curDiff -= (queueValues[middleIndex] - queueValues[frontIndex]);
        frontIndex++;
        if (middleIndex < (backIndex + frontIndex) / 2) middleIndex++;
        leftIndex++;
    }
    return (int) maxDiff;
}