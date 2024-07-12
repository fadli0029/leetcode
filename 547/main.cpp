#include "bits/stdc++.h"
#include "helpers.cpp"
using namespace std;

class Solution {
public:
    // We can use the disjoint set data structure to solve
    // this problem.

    class DisjointSet {
        public:
            DisjointSet(int size) {
                repr.resize(size);
                rank.resize(size);
                for (int i=0; i<size; i++) {
                    repr[i] = i;
                    rank[i] = 1;
                }
            }

            int find(int node) {
                if (node == repr[node]) {
                    return node;
                }

                // path compression
                return repr[node] = find(repr[node]);
            }

            void merge(int node1, int node2) {
                int repr_node1 = find(node1);
                int repr_node2 = find(node2);
                if (repr_node1 != repr_node2) {
                    if (rank[repr_node1] > rank[repr_node2]) {
                        repr[repr_node2] = repr_node1;
                    }
                    else if (rank[repr_node1] < rank[repr_node2]) {
                        repr[repr_node1] = repr_node2;
                    }
                    else {
                        repr[repr_node2] = repr_node1;
                        rank[repr_node1]++;
                    }
                }
            }

            bool connected(int node1, int node2) {
                return find(node1) == find(node2);
            }

        private:
            vector<int> repr;
            vector<int> rank;
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        int n_components = n;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (isConnected[i][j] && !ds.connected(i, j)) {
                    n_components--;
                    ds.merge(i, j);
                }
            }
        }
        return n_components;
    }
};

int main() {
    Solution sol;
    return 0;
}

