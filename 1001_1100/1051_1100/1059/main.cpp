#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> status(n, 0);  // 0: unvisited, 1: visiting, 2: visited

        // Build the graph adjacency list
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        function<bool(int)> dfs = [&](int node) -> bool {
            if (status[node] == 1) return false;  // cycle detected
            if (status[node] == 2) return true;   // already processed
            if (graph[node].empty() && node != destination) return false;  // dead-end

            status[node] = 1;  // mark as visiting

            for (const int& neighbor : graph[node]) {
                if (!dfs(neighbor)) return false;
            }

            // no more neighbors for the current node,
            // mark it as visited.
            status[node] = 2;
            return true;
        };

        return dfs(source);
    }
};


int main() {
    Solution sol;
    return 0;
}

