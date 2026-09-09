#pragma GCC optimize (2)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;
const int MAX_NODES = 10;
vector<vector<int>> adjacencyList(MAX_NODES);
vector<int> nodeColor(MAX_NODES);

int bfs(int source) {
    int maxColor = 1;
    nodeColor[source] = 1;
    queue<int> buffer;
    buffer.push(source);

    while (!buffer.empty()) {
        int currentNode = buffer.front();
        vector<bool> availableColors(5, true);
        buffer.pop();

        for (auto &neighbor : adjacencyList[currentNode]) {
            if (nodeColor[neighbor])
                availableColors[nodeColor[neighbor]] = false;
            else
                buffer.push(neighbor);
        }

        for (int color = 1; color < 5; color++) {
            if (availableColors[color]) {
                nodeColor[currentNode] = color;
                maxColor = max(maxColor, color);
                break;
            } else if (color == 4) {
                return numeric_limits<int>::max();
            }
        }
    }
    return maxColor;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int t = 0; t < 5; t++) {
        int numberOfEdges, nodeA, nodeB, maxColor = 1;
        cin >> numberOfEdges;
        adjacencyList.assign(MAX_NODES, vector<int>());
        nodeColor.assign(MAX_NODES, 0);

        while (numberOfEdges--) {
            cin >> nodeA >> nodeB;
            if (nodeA == nodeB) continue;
            adjacencyList[nodeA].push_back(nodeB);
            adjacencyList[nodeB].push_back(nodeA);
        }

        for (int node = 1; node < MAX_NODES; node++)
            if (!nodeColor[node])
                maxColor = max(maxColor, bfs(node));

        cout << (maxColor == numeric_limits<int>::max() ? 0 : maxColor) << '\n';
    }
    return 0;
}