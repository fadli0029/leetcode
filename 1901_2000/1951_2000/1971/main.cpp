#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build the graph;
        vector<int> g[n];
        for (const auto& e : edges) {
            g[e.at(0)].push_back(e.at(1));
            g[e.at(1)].push_back(e.at(0));
        }

        // dfs
        stack<int> st;
        vector<bool> visited(n, false);

        st.push(source);
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (node == destination) {
                return true;
            }

            if (!visited[node]) {
                visited[node] = true;
                // explore its neighbors
                for (const auto& nbr : g[node]) {
                    if (!visited[nbr]) {
                        st.push(nbr);
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    return 0;
}

