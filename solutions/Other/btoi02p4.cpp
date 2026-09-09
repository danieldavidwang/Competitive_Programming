#include <bits/stdc++.h>
using namespace std;
struct Edge { int destination, distance, cost; };
bool operator<(const Edge &a, const Edge &b) { return a.distance > b.distance; }
vector<Edge> graph[101];
priority_queue<Edge> pq;
int high[101], n, m, s, e;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(high, 0x3f, sizeof(high));
    cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++) {
        int start, end, distance, cost;
        cin >> start >> end >> distance >> cost;
        graph[start].push_back({end, distance, cost});
        graph[end].push_back({start, distance, cost});
    }

    pq.push({s, 0, 0});
    int result = 0, highestCost = 1e9;

    while (!pq.empty()) {
        Edge current = pq.top(); pq.pop();
        if (high[current.destination] <= current.cost) continue;
        high[current.destination] = current.cost;
        if (current.destination == e) {
            if (highestCost == current.distance) continue;
            highestCost = current.distance;
            result += 2;
        }
        for (auto &neighbor : graph[current.destination]) pq.push({neighbor.destination, current.distance + neighbor.distance, current.cost + neighbor.cost});
    }

    cout << (result/2) << '\n';
    return 0;
}