#include <bits/stdc++.h>
using namespace std;

int find_subset(int lower_bound, int upper_bound, int weights[], int size, int result[]) {
    vector<pair<long long, int>> weight_index_pairs(size);
    for (int i = 0; i < size; i++) weight_index_pairs[i] = {weights[i], i};
    sort(weight_index_pairs.begin(), weight_index_pairs.end());
    long long prev_sum = 0;
    for (int i = 0; i < size; i++) {
        weight_index_pairs[i].first += prev_sum;
        prev_sum = weight_index_pairs[i].first;
    }
    int j = 0;
    for (int i = 0; i < size; i++) {
        while (j < size) {
            long long sum = weight_index_pairs[j].first;
            if (i > 0) sum -= weight_index_pairs[i - 1].first;
            if (sum < lower_bound) j++;
            else break;
        }
        if (j == size) return 0;
        long long value = weight_index_pairs[j].first;
        if (i > 0) value -= weight_index_pairs[i - 1].first;
        if (lower_bound <= value && value <= upper_bound) {
            for (int k = 0; k < j - i + 1; k++) result[k] = weight_index_pairs[i + k].second;
            return (j - i + 1);
        }
    }
    return 0;
}