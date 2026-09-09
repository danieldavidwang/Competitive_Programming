#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int n, l, w; long long arr[MM], result[MM];

int find_subset(int lower_bound, int upper_bound, long long weights[], int size, long long result[]) {
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> w;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int x = find_subset(l, w, arr, n, result);
    cout << x << '\n';
    for (int i = 0; i < x; i++) cout << result[i] << ' ';
    cout << '\n';
    return 0;
}